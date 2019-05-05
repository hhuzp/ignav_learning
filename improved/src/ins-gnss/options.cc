/*------------------------------------------------------------------------------
* options.cc : options functions
*
* version : $Revision:$ $Date:$
* history : 2010/07/20  1.1  moved from postpos.c
*                            added api:
*                                searchopt(),str2opt(),opt2str(),opt2buf(),
*                                loadopts(),saveopts(),resetsysopts(),
*                                getsysopts(),setsysopts()
*           2010/09/11  1.2  add options
*                                pos2-elmaskhold,pos1->snrmaskena
*                                pos1-snrmask1,2,3
*           2013/03/11  1.3  add pos1-posopt1,2,3,4,5,pos2-syncsol
*                                misc-rnxopt1,2,pos1-snrmask_r,_b,_L1,_L2,_L5
*           2014/10/21  1.4  add pos2-bdsarmode
*           2015/02/20  1.4  add ppp-fixed as pos1-posmode option
*           2015/05/10  1.5  add pos2-arthres1,2,3,4
*           2015/05/31  1.6  add pos2-armaxiter, pos1-posopt6
*                            add selection precise for pos1-pospot3
*           2015/11/26  1.7  modify pos1-frequency 4:l1+l2+l5+l6 -> l1+l5
*           2015/12/05  1.8  add misc-pppopt
*           2016/06/10  1.9  add ant2-maxaveep,ant2-initrst
*           2016/07/31  1.10 add out-outsingle,out-maxsolstd
*           2017/06/14  1.11 add out-outvel
*-----------------------------------------------------------------------------*/
#include <include/carvig.h>
#include "carvig.h"

/* system options buffer -----------------------------------------------------*/
static prcopt_t prcopt_;
static solopt_t solopt_;
static filopt_t filopt_;
static int antpostype_[2];
static double elmask_,elmaskar_,elmaskhold_;
static double antpos_[2][3];
static char exsats_[1024];
static char snrmask_[NFREQ][1024];

/* system options table ------------------------------------------------------*/
#define SWTOPT  "0:off,1:on"
#define MODOPT  "0:single,1:dgps,2:kinematic,3:static,4:movingbase,5:fixed,6:ppp-kine,7:ppp-static,8:ppp-fixed,9:ins-update,10:ins-loosely-coupled,11:ins-tightly-coupled,12:ins-gnsslc-vo-coupled"
#define FRQOPT  "1:l1,2:l1+l2,3:l1+l2+l5,4:l1+l5"
#define TYPOPT  "0:forward,1:backward,2:combined,3:RTS"
#define IONOPT  "0:off,1:brdc,2:sbas,3:dual-freq,4:est-stec,5:ionex-tec,6:qzs-brdc,7:qzs-lex,8:stec"
#define TRPOPT  "0:off,1:saas,2:sbas,3:est-ztd,4:est-ztdgrad,5:ztd"
#define EPHOPT  "0:brdc,1:precise,2:brdc+sbas,3:brdc+ssrapc,4:brdc+ssrcom"
#define NAVOPT  "1:gps+2:sbas+4:glo+8:gal+16:qzs+32:comp"
#define GAROPT  "0:off,1:on,2:autocal"
#define SOLOPT  "0:llh,1:xyz,2:enu,3:nmea,4:stat,5:gsif,6:ins,7:vo"
#define TSYOPT  "0:gpst,1:utc,2:jst"
#define TFTOPT  "0:tow,1:hms"
#define DFTOPT  "0:deg,1:dms"
#define HGTOPT  "0:ellipsoidal,1:geodetic"
#define GEOOPT  "0:internal,1:egm96,2:egm08_2.5,3:egm08_1,4:gsi2000"
#define STAOPT  "0:all,1:single"
#define STSOPT  "0:off,1:state,2:residual"
#define ARMOPT  "0:off,1:continuous,2:instantaneous,3:fix-and-hold,4:pppar,5:pppar-ils,6:wlnl,7:tcar,8:wlnlc,9:tcarc"
#define POSOPT  "0:llh,1:xyz,2:single,3:posfile,4:rinexhead,5:rtcm,6:raw"
#define TIDEOPT "0:off,1:on,2:otl"
#define PHWOPT  "0:off,1:on,2:precise"

EXPORT opt_t sysopts[]={
    {"pos1-posmode",    3,  (void *)&prcopt_.mode,       MODOPT },
    {"pos1-frequency",  3,  (void *)&prcopt_.nf,         FRQOPT },
    {"pos1-soltype",    3,  (void *)&prcopt_.soltype,    TYPOPT },
    {"pos1-elmask",     1,  (void *)&elmask_,            "deg"  },
    {"pos1-snrmask_r",  3,  (void *)&prcopt_.snrmask.ena[0],SWTOPT},
    {"pos1-snrmask_b",  3,  (void *)&prcopt_.snrmask.ena[1],SWTOPT},
    {"pos1-snrmask_L1", 2,  (void *)snrmask_[0],         ""     },
    {"pos1-snrmask_L2", 2,  (void *)snrmask_[1],         ""     },
    {"pos1-snrmask_L5", 2,  (void *)snrmask_[2],         ""     },
    {"pos1-dynamics",   3,  (void *)&prcopt_.dynamics,   SWTOPT },
    {"pos1-tidecorr",   3,  (void *)&prcopt_.tidecorr,   TIDEOPT},
    {"pos1-ionoopt",    3,  (void *)&prcopt_.ionoopt,    IONOPT },
    {"pos1-tropopt",    3,  (void *)&prcopt_.tropopt,    TRPOPT },
    {"pos1-sateph",     3,  (void *)&prcopt_.sateph,     EPHOPT },
    {"pos1-posopt1",    3,  (void *)&prcopt_.posopt[0],  SWTOPT },
    {"pos1-posopt2",    3,  (void *)&prcopt_.posopt[1],  SWTOPT },
    {"pos1-posopt3",    3,  (void *)&prcopt_.posopt[2],  PHWOPT },
    {"pos1-posopt4",    3,  (void *)&prcopt_.posopt[3],  SWTOPT },
    {"pos1-posopt5",    3,  (void *)&prcopt_.posopt[4],  SWTOPT },
    {"pos1-posopt6",    3,  (void *)&prcopt_.posopt[5],  SWTOPT },
    {"pos1-exclsats",   2,  (void *)exsats_,             "prn ..."},
    {"pos1-navsys",     0,  (void *)&prcopt_.navsys,     NAVOPT },
    {"pos1-adjobs",     0,  (void *)&prcopt_.adjobs,     ""     },
    {"pos1-eps",        1,  (void *)&prcopt_.eps,        ""     },
    {"pos1-gtfmt",      0,  (void *)&prcopt_.gtfmt,      ""     },
    
    {"pos2-armode",     3,  (void *)&prcopt_.modear,     ARMOPT },
    {"pos2-gloarmode",  3,  (void *)&prcopt_.glomodear,  GAROPT },
    {"pos2-bdsarmode",  3,  (void *)&prcopt_.bdsmodear,  SWTOPT },
    {"pos2-arthres",    1,  (void *)&prcopt_.thresar[0], ""     },
    {"pos2-arthres1",   1,  (void *)&prcopt_.thresar[1], ""     },
    {"pos2-arthres2",   1,  (void *)&prcopt_.thresar[2], ""     },
    {"pos2-arthres3",   1,  (void *)&prcopt_.thresar[3], ""     },
    {"pos2-arthres4",   1,  (void *)&prcopt_.thresar[4], ""     },
    {"pos2-arlockcnt",  0,  (void *)&prcopt_.minlock,    ""     },
    {"pos2-arelmask",   1,  (void *)&elmaskar_,          "deg"  },
    {"pos2-arminfix",   0,  (void *)&prcopt_.minfix,     ""     },
    {"pos2-armaxiter",  0,  (void *)&prcopt_.armaxiter,  ""     },
    {"pos2-elmaskhold", 1,  (void *)&elmaskhold_,        "deg"  },
    {"pos2-aroutcnt",   0,  (void *)&prcopt_.maxout,     ""     },
    {"pos2-maxage",     1,  (void *)&prcopt_.maxtdiff,   "s"    },
    {"pos2-syncsol",    3,  (void *)&prcopt_.syncsol,    SWTOPT },
    {"pos2-slipthres",  1,  (void *)&prcopt_.thresslip,  "m"    },
    {"pos2-rejionno",   1,  (void *)&prcopt_.maxinno,    "m"    },
    {"pos2-rejgdop",    1,  (void *)&prcopt_.maxgdop,    ""     },
    {"pos2-niter",      0,  (void *)&prcopt_.niter,      ""     },
    {"pos2-baselen",    1,  (void *)&prcopt_.baseline[0],"m"    },
    {"pos2-basesig",    1,  (void *)&prcopt_.baseline[1],"m"    },
    
    {"out-solformat",   3,  (void *)&solopt_.posf,       SOLOPT },
    {"out-outhead",     3,  (void *)&solopt_.outhead,    SWTOPT },
    {"out-outopt",      3,  (void *)&solopt_.outopt,     SWTOPT },
    {"out-outvel",      3,  (void *)&solopt_.outvel,     SWTOPT },
    {"out-timesys",     3,  (void *)&solopt_.times,      TSYOPT },
    {"out-timeform",    3,  (void *)&solopt_.timef,      TFTOPT },
    {"out-timendec",    0,  (void *)&solopt_.timeu,      ""     },
    {"out-degform",     3,  (void *)&solopt_.degf,       DFTOPT },
    {"out-fieldsep",    2,  (void *) solopt_.sep,        ""     },
    {"out-outsingle",   3,  (void *)&prcopt_.outsingle,  SWTOPT },
    {"out-maxsolstd",   1,  (void *)&solopt_.maxsolstd,  "m"    },
    {"out-height",      3,  (void *)&solopt_.height,     HGTOPT },
    {"out-geoid",       3,  (void *)&solopt_.geoid,      GEOOPT },
    {"out-solstatic",   3,  (void *)&solopt_.solstatic,  STAOPT },
    {"out-nmeaintv1",   1,  (void *)&solopt_.nmeaintv[0],"s"    },
    {"out-nmeaintv2",   1,  (void *)&solopt_.nmeaintv[1],"s"    },
    {"out-outstat",     3,  (void *)&solopt_.sstat,      STSOPT },
    {"out-att",         0,  (void *)&solopt_.outatt,     ""     },
    {"out-acc",         0,  (void *)&solopt_.outacc,     ""     },
    {"out-vel",         0,  (void *)&solopt_.outvel,     ""     },
    {"out-vb",          0,  (void *)&solopt_.outvb,      ""     },
    {"out-ba",          0,  (void *)&solopt_.outba,      ""     },
    {"out-bg",          0,  (void *)&solopt_.outbg,      ""     },
    {"out-inspof",      0,  (void *)&solopt_.ins_posf,   ""     },
    {"out-imuraw",      0,  (void *)&solopt_.outimuraw,  ""     },
    {"out-Ma",          0,  (void *)&solopt_.outMa,      ""     },
    {"out-Mg",          0,  (void *)&solopt_.outMg,      ""     },
    {"out-vo",          0,  (void *)&solopt_.outvo,      ""     },
    {"out-enu",          0,  (void *)&solopt_.outenu,    ""     },
    
    {"stats-eratio1",   1,  (void *)&prcopt_.eratio[0],  ""     },
    {"stats-eratio2",   1,  (void *)&prcopt_.eratio[1],  ""     },
    {"stats-errphase",  1,  (void *)&prcopt_.err[1],     "m"    },
    {"stats-errphaseel",1,  (void *)&prcopt_.err[2],     "m"    },
    {"stats-errphasebl",1,  (void *)&prcopt_.err[3],     "m/10km"},
    {"stats-errdoppler",1,  (void *)&prcopt_.err[4],     "Hz"   },
    {"stats-stdbias",   1,  (void *)&prcopt_.std[0],     "m"    },
    {"stats-stdiono",   1,  (void *)&prcopt_.std[1],     "m"    },
    {"stats-stdtrop",   1,  (void *)&prcopt_.std[2],     "m"    },
    {"stats-prnaccelh", 1,  (void *)&prcopt_.prn[3],     "m/s^2"},
    {"stats-prnaccelv", 1,  (void *)&prcopt_.prn[4],     "m/s^2"},
    {"stats-prnbias",   1,  (void *)&prcopt_.prn[0],     "m"    },
    {"stats-prniono",   1,  (void *)&prcopt_.prn[1],     "m"    },
    {"stats-prntrop",   1,  (void *)&prcopt_.prn[2],     "m"    },
    {"stats-prnpos",    1,  (void *)&prcopt_.prn[5],     "m"    },
    {"stats-clkstab",   1,  (void *)&prcopt_.sclkstab,   "s/s"  },
    
    {"ant1-postype",    3,  (void *)&antpostype_[0],     POSOPT },
    {"ant1-pos1",       1,  (void *)&antpos_[0][0],      "deg|m"},
    {"ant1-pos2",       1,  (void *)&antpos_[0][1],      "deg|m"},
    {"ant1-pos3",       1,  (void *)&antpos_[0][2],      "m|m"  },
    {"ant1-anttype",    2,  (void *)prcopt_.anttype[0],  ""     },
    {"ant1-antdele",    1,  (void *)&prcopt_.antdel[0][0],"m"   },
    {"ant1-antdeln",    1,  (void *)&prcopt_.antdel[0][1],"m"   },
    {"ant1-antdelu",    1,  (void *)&prcopt_.antdel[0][2],"m"   },
    
    {"ant2-postype",    3,  (void *)&antpostype_[1],     POSOPT },
    {"ant2-pos1",       1,  (void *)&antpos_[1][0],      "deg|m"},
    {"ant2-pos2",       1,  (void *)&antpos_[1][1],      "deg|m"},
    {"ant2-pos3",       1,  (void *)&antpos_[1][2],      "m|m"  },
    {"ant2-anttype",    2,  (void *)prcopt_.anttype[1],  ""     },
    {"ant2-antdele",    1,  (void *)&prcopt_.antdel[1][0],"m"   },
    {"ant2-antdeln",    1,  (void *)&prcopt_.antdel[1][1],"m"   },
    {"ant2-antdelu",    1,  (void *)&prcopt_.antdel[1][2],"m"   },
    {"ant2-maxaveep",   0,  (void *)&prcopt_.maxaveep    ,""    },
    {"ant2-initrst",    3,  (void *)&prcopt_.initrst,    SWTOPT },
    
    {"misc-timeinterp", 3,  (void *)&prcopt_.intpref,    SWTOPT },
    {"misc-sbasatsel",  0,  (void *)&prcopt_.sbassatsel, "0:all"},
    {"misc-rnxopt1",    2,  (void *)prcopt_.rnxopt[0],   ""     },
    {"misc-rnxopt2",    2,  (void *)prcopt_.rnxopt[1],   ""     },
    {"misc-pppopt",     2,  (void *)prcopt_.pppopt,      ""     },

    {"file-satantfile", 2,  (void *)filopt_.satantp,     ""     },
    {"file-rcvantfile", 2,  (void *)filopt_.rcvantp,     ""     },
    {"file-staposfile", 2,  (void *)filopt_.stapos,      ""     },
    {"file-geoidfile",  2,  (void *)filopt_.geoid,       ""     },
    {"file-ionofile",   2,  (void *)filopt_.iono,        ""     },
    {"file-dcbfile",    2,  (void *)filopt_.dcb,         ""     },
    {"file-eopfile",    2,  (void *)filopt_.eop,         ""     },
    {"file-blqfile",    2,  (void *)filopt_.blq,         ""     },
    {"file-tempdir",    2,  (void *)filopt_.tempdir,     ""     },
    {"file-geexefile",  2,  (void *)filopt_.geexe,       ""     },
    {"file-solstatfile",2,  (void *)filopt_.solstat,     ""     },
    {"file-tracefile",  2,  (void *)filopt_.trace,       ""     },
    {"file-navfile",    2,  (void *)filopt_.navfile,     ""     },
    {"file-bdsfile",    2,  (void *)filopt_.bdsfile,     ""     },
    {"file-monodir",    2,  (void *)prcopt_.monodir,     ""     },
    {"file-gtfile",     2,  (void *)filopt_.gtfile,      ""     },
    {"file-magfile",    2,  (void *)filopt_.magfile,     ""     },
    {"file-glofile",    2,  (void *)filopt_.glofile,     ""     },
    {"file-mixfile",    2,  (void *)filopt_.mixfile,     ""     },

    {"",0,NULL,""} /* terminator */
};
EXPORT opt_t insopts[]={
    {"ins-leverarm1",   1, (void *)&prcopt_.insopt.lever[0], "" },
    {"ins-leverarm2",   1, (void *)&prcopt_.insopt.lever[1], "" },
    {"ins-leverarm3",   1, (void *)&prcopt_.insopt.lever[2], "" },
    {"ins-gravityex",   0, (void *)&prcopt_.insopt.gravityex,"" },
    {"ins-updint",      0, (void *)&prcopt_.insopt.updint,   "" },
    {"ins-baopt",       0, (void *)&prcopt_.insopt.baopt,    "" },
    {"ins-bgopt",       0, (void *)&prcopt_.insopt.bgopt,    "" },
    {"ins-estsg",       0, (void *)&prcopt_.insopt.estsg,    "" },
    {"ins-estsa",       0, (void *)&prcopt_.insopt.estsa,    "" },
    {"ins-estdt",       0, (void *)&prcopt_.insopt.estdt,    "" },
    {"ins-estrg",       0, (void *)&prcopt_.insopt.estrg,    "" },
    {"ins-estra",       0, (void *)&prcopt_.insopt.estra,    "" },
    {"ins-estlever",    0, (void *)&prcopt_.insopt.estlever, "" },
    {"ins-estodos",     0, (void *)&prcopt_.insopt.estodos,  "" },
    {"ins-estodoa",     0, (void *)&prcopt_.insopt.estodoa,  "" },
    {"ins-estodol",     0, (void *)&prcopt_.insopt.estodol,  "" },
    {"ins-estmisv",     0, (void *)&prcopt_.insopt.estmisv,  "" },
    {"ins-estcaml",     0, (void *)&prcopt_.insopt.estcaml,  "" },
    {"ins-estcamfo",    0, (void *)&prcopt_.insopt.estcam_fo,"" },
    {"ins-estcamkp",    0, (void *)&prcopt_.insopt.estcam_kp,"" },
    
    {"ins-baproopt",    0, (void *)&prcopt_.insopt.baproopt, "" },
    {"ins-bgproopt",    0, (void *)&prcopt_.insopt.bgproopt, "" },
    {"ins-sgproopt",    0, (void *)&prcopt_.insopt.sgproopt, "" },
    {"ins-saproopt",    0, (void *)&prcopt_.insopt.saproopt, "" },
    {"ins-dtproopt",    0, (void *)&prcopt_.insopt.dtproopt, "" },
    {"ins-rgproopt",    0, (void *)&prcopt_.insopt.rgproopt, "" },
    {"ins-raproopt",    0, (void *)&prcopt_.insopt.raproopt, "" },
    {"ins-osproopt",    0, (void *)&prcopt_.insopt.osproopt, "" },
    {"ins-olproopt",    0, (void *)&prcopt_.insopt.olproopt, "" },
    {"ins-oaproopt",    0, (void *)&prcopt_.insopt.oaproopt, "" },
    {"ins-cmaopt",      0, (void *)&prcopt_.insopt.cmaopt,   "" },
    {"ins-vmaopt",      0, (void *)&prcopt_.insopt.vmaopt,   "" },
    {"ins-foproopt",    0, (void *)&prcopt_.insopt.cfoopt,   "" },
    {"ins-kpproopt",    0, (void *)&prcopt_.insopt.ckpopt,   "" },
    {"ins-claopt",      0, (void *)&prcopt_.insopt.claopt,   "" },

    {"ins-imuformat",   0, (void *)&prcopt_.insopt.imuformat,"" },
    {"ins-imudecfmt",   0, (void *)&prcopt_.insopt.imudecfmt,"" },
    {"ins-imucoors",    0, (void *)&prcopt_.insopt.imucoors, "" },
    {"ins-imuvalfmt",   0, (void *)&prcopt_.insopt.imuvalfmt,"" },
    {"ins-exprn",       0, (void *)&prcopt_.insopt.exprn,    "" },
    {"ins-exphi",       0, (void *)&prcopt_.insopt.exphi,    "" },
    {"ins-exvm",        0, (void *)&prcopt_.insopt.exvm,     "" },
    {"ins-iisu",        0, (void *)&prcopt_.insopt.iisu,     "" },
    {"ins-nhc",         0, (void *)&prcopt_.insopt.nhc,      "" },
    {"ins-zvu",         0, (void *)&prcopt_.insopt.zvu,      "" },
    {"ins-zaru",        0, (void *)&prcopt_.insopt.zaru,     "" },
    {"ins-detst",       0, (void *)&prcopt_.insopt.detst,    "" },
    {"ins-tc",          0, (void *)&prcopt_.insopt.tc,       "" },
    {"ins-lc",          0, (void *)&prcopt_.insopt.lc,       "" },
    {"ins-doppler",     0, (void *)&prcopt_.insopt.dopp,     "" },
    {"ins-intpref",     0, (void *)&prcopt_.insopt.intpref,  "" },
    {"ins-minp",        0, (void *)&prcopt_.insopt.minp,     "" },
    {"ins-hz",          1, (void *)&prcopt_.insopt.hz,       "" },
    {"ins-nhz",         1, (void *)&prcopt_.insopt.nhz,      "" },
    {"ins-lcopt",       0, (void *)&prcopt_.insopt.lcopt,    "" },
    {"ins-pose-aid",    0, (void *)&prcopt_.insopt.pose_aid, "" },
    {"ins-exinserr",    0, (void *)&prcopt_.insopt.exinserr, ""},

    {"ins-align-dualant",0,(void *)&prcopt_.insopt.align_dualants,""},
    {"ins-align-given"  ,0,(void *)&prcopt_.insopt.align_given,   ""},
    {"ins-mis-v2b-euler1",1,(void *)&prcopt_.insopt.mis_euler[0], ""},
    {"ins-mis-v2b-euler2",1,(void *)&prcopt_.insopt.mis_euler[1], ""},
    {"ins-mis-v2b-euler3",1,(void *)&prcopt_.insopt.mis_euler[2], ""},

    {"ins-align-given-att1",1,(void *)&prcopt_.insopt.att0[0],""},
    {"ins-align-given-att2",1,(void *)&prcopt_.insopt.att0[1],""},
    {"ins-align-given-att3",1,(void *)&prcopt_.insopt.att0[2],""},
    {"ins-align-given-vn1",1,(void *)&prcopt_.insopt.vn0[0],  ""},
    {"ins-align-given-vn2",1,(void *)&prcopt_.insopt.vn0[1],  ""},
    {"ins-align-given-vn3",1,(void *)&prcopt_.insopt.vn0[2],  ""},
    {"ins-align-given-rn1",1,(void *)&prcopt_.insopt.rn0[0],  ""},
    {"ins-align-given-rn2",1,(void *)&prcopt_.insopt.rn0[1],  ""},
    {"ins-align-given-rn3",1,(void *)&prcopt_.insopt.rn0[2],  ""},
    {"ins-align-given-t0" ,1,(void *)&prcopt_.insopt.t0    ,  ""},

    {"ins-uncatt",      1, (void *)&prcopt_.insopt.unc.att,  "" },
    {"ins-uncvel",      1, (void *)&prcopt_.insopt.unc.vel,  "" },
    {"ins-uncpos",      1, (void *)&prcopt_.insopt.unc.pos,  "" },
    {"ins-uncba",       1, (void *)&prcopt_.insopt.unc.ba,   "" },
    {"ins-uncbg",       1, (void *)&prcopt_.insopt.unc.bg,   "" },
    {"ins-uncdt",       1, (void *)&prcopt_.insopt.unc.dt,   "" },
    {"ins-uncsg",       1, (void *)&prcopt_.insopt.unc.sg,   "" },
    {"ins-uncsa",       1, (void *)&prcopt_.insopt.unc.sa,   "" },
    {"ins-uncra",       1, (void *)&prcopt_.insopt.unc.ra,   "" },
    {"ins-uncrg",       1, (void *)&prcopt_.insopt.unc.rg,   "" },
    {"ins-unclever",    1, (void *)&prcopt_.insopt.unc.lever,"" },
    {"ins-uncos",       1, (void *)&prcopt_.insopt.unc.os,   "" },
    {"ins-uncoa",       1, (void *)&prcopt_.insopt.unc.oa,   "" },
    {"ins-uncol",       1, (void *)&prcopt_.insopt.unc.ol,   "" },
    {"ins-uncrr",       1, (void *)&prcopt_.insopt.unc.rr,   "" },
    {"ins-uncrc",       1, (void *)&prcopt_.insopt.unc.rc,   "" },
    {"ins-uncma",       1, (void *)&prcopt_.insopt.unc.cma,  "" },
    {"ins-unvma",       1, (void *)&prcopt_.insopt.unc.vma,  "" },

    {"ins-unccaml",     1, (void *)&prcopt_.insopt.unc.lma,   ""},
    {"ins-unccamfo-1",  1, (void *)&prcopt_.insopt.unc.fo[0], ""},
    {"ins-unccamfo-2",  1, (void *)&prcopt_.insopt.unc.fo[1], ""},
    {"ins-unccamfo-3",  1, (void *)&prcopt_.insopt.unc.fo[2], ""},
    {"ins-unccamfo-4",  1, (void *)&prcopt_.insopt.unc.fo[3], ""},

    {"ins-unccamkp-1",  1, (void *)&prcopt_.insopt.unc.kp[0], ""},
    {"ins-unccamkp-2",  1, (void *)&prcopt_.insopt.unc.kp[1], ""},
    {"ins-unccamkp-3",  1, (void *)&prcopt_.insopt.unc.kp[2], ""},
    {"ins-unccamkp-4",  1, (void *)&prcopt_.insopt.unc.kp[3], ""},

    {"ins-psd_gyro",    1, (void *)&prcopt_.insopt.psd.gyro, "" },
    {"ins-psd_accl",    1, (void *)&prcopt_.insopt.psd.accl, "" },
    {"ins-psd_ba",      1, (void *)&prcopt_.insopt.psd.ba,   "" },
    {"ins-psd_bg",      1, (void *)&prcopt_.insopt.psd.bg,   "" },
    {"ins-psd_clk",     1, (void *)&prcopt_.insopt.psd.clk,  "" },
    {"ins-psd_clkr",    1, (void *)&prcopt_.insopt.psd.clkr, "" },

    {"ins-zv_mt",         1, (void *)&prcopt_.insopt.zvopt.mt,          "" },
    {"ins-zv_ws",         0, (void *)&prcopt_.insopt.zvopt.ws,          "" },
    {"ins-zv_sp",         1, (void *)&prcopt_.insopt.zvopt.sp,          "" },
    {"ins-zv_gthres",     1, (void *)&prcopt_.insopt.zvopt.gthres,      "" },
    {"ins-zv_athres1",    1, (void *)&prcopt_.insopt.zvopt.athres[0],   "" },
    {"ins-zv_athres2",    1, (void *)&prcopt_.insopt.zvopt.athres[1],   "" },
    {"ins-zv_athres3",    1, (void *)&prcopt_.insopt.zvopt.athres[2],   "" },
    {"ins-zv_gyrothres1", 1, (void *)&prcopt_.insopt.zvopt.gyrothres[0],"" },
    {"ins-zv_gyrothres2", 1, (void *)&prcopt_.insopt.zvopt.gyrothres[1],"" },
    {"ins-zv_gyrothres3", 1, (void *)&prcopt_.insopt.zvopt.gyrothres[2],"" },
    {"ins-zv_odt",        1, (void *)&prcopt_.insopt.zvopt.odt,         "" },
    {"ins-zv_siga",       1, (void *)&prcopt_.insopt.zvopt.sig_a,       "" },
    {"ins-zv_sigg",       1, (void *)&prcopt_.insopt.zvopt.sig_g,       "" },

    {"ins-zv_gamma1",     1, (void *)&prcopt_.insopt.zvopt.gamma[0],    "" },
    {"ins-zv_gamma2",     1, (void *)&prcopt_.insopt.zvopt.gamma[1],    "" },
    {"ins-zv_gamma3",     1, (void *)&prcopt_.insopt.zvopt.gamma[2],    "" },
    {"ins-zv_gamma4",     1, (void *)&prcopt_.insopt.zvopt.gamma[3],    "" },

    {"ins-odo_dir",       0, (void *)&prcopt_.insopt.odopt.dir,         "" },
    {"ins-odo_all",       0, (void *)&prcopt_.insopt.odopt.all,         "" },
    {"ins-odo_res",       1, (void *)&prcopt_.insopt.odopt.res,         "" },
    {"ins-odo_s",         1, (void *)&prcopt_.insopt.odopt.s,           "" },
    {"ins-odo_d",         1, (void *)&prcopt_.insopt.odopt.d,           "" },
    {"ins-odo_odt",       1, (void *)&prcopt_.insopt.odopt.odt,         "" },
    {"ins-odo_ostd",      1, (void *)&prcopt_.insopt.odopt.ostd,        "" },
    {"ins-odo_lever1",    1, (void *)&prcopt_.insopt.odopt.lever[0],    "" },
    {"ins-odo_lever2",    1, (void *)&prcopt_.insopt.odopt.lever[1],    "" },
    {"ins-odo_lever3",    1, (void *)&prcopt_.insopt.odopt.lever[2],    "" },

    {"ins-vo-aid-calib-f",      1, (void *)&prcopt_.insopt.voopt.calib.f,     "" },
    {"ins-vo-aid-calib-fu",     1, (void *)&prcopt_.insopt.voopt.calib.fu,    "" },
    {"ins-vo-aid-calib-fv",     1, (void *)&prcopt_.insopt.voopt.calib.fv,    "" },
    {"ins-vo-aid-calib-cu",     1, (void *)&prcopt_.insopt.voopt.calib.cu,    "" },
    {"ins-vo-aid-calib-cv",     1, (void *)&prcopt_.insopt.voopt.calib.cv,    "" },
    {"ins-vo-aid-height",       1, (void *)&prcopt_.insopt.voopt.height,      "" },
    {"ins-vo-aid-inlier-thres", 1, (void *)&prcopt_.insopt.voopt.inlier_thres,"" },
    {"ins-vo-aid-motion-thres", 1, (void *)&prcopt_.insopt.voopt.motion_thres,"" },
    {"ins-vo-aid-ransac-iters", 0, (void *)&prcopt_.insopt.voopt.ransac_iters,"" },
    {"ins-vo-aid-bucket-w",     1, (void *)&prcopt_.insopt.voopt.match.bucket.w,    "" },
    {"ins-vo-aid-bucket-h",     1, (void *)&prcopt_.insopt.voopt.match.bucket.h,    "" },
    {"ins-vo-aid-bucket-nmax",  0, (void *)&prcopt_.insopt.voopt.match.bucket.nmax, "" },

    {"ins-vo-aid-match-binsize"   ,0,(void *)&prcopt_.insopt.voopt.match.match_binsize,   ""},
    {"ins-vo-aid-match-radius"    ,0,(void *)&prcopt_.insopt.voopt.match.match_radius,    ""},
    {"ins-vo-aid-match-disp_tol"  ,0,(void *)&prcopt_.insopt.voopt.match.match_disp_tol,  ""},
    {"ins-vo-aid-outlier-disp_tol",0,(void *)&prcopt_.insopt.voopt.match.outlier_disp_tol,""},
    {"ins-vo-aid-outlier-flow_tol",0,(void *)&prcopt_.insopt.voopt.match.outlier_flow_tol,""},
    {"ins-vo-aid-match-roi1",      0,(void *)&prcopt_.insopt.voopt.match.roi[0][0],""},
    {"ins-vo-aid-match-roi2",      0,(void *)&prcopt_.insopt.voopt.match.roi[0][1],""},
    {"ins-vo-aid-match-roi3",      0,(void *)&prcopt_.insopt.voopt.match.roi[1][0],""},
    {"ins-vo-aid-match-roi4",      0,(void *)&prcopt_.insopt.voopt.match.roi[1][1],""},

    {"ins-vo-aid-multi-stage",0,(void *)&prcopt_.insopt.voopt.match.multi_stage},
    {"ins-vo-aid-half-res"   ,0,(void *)&prcopt_.insopt.voopt.match.half_res   },
    {"ins-vo-aid-refine"     ,0,(void *)&prcopt_.insopt.voopt.match.refine     },
    {"ins-vo-aid-nms-n"      ,0,(void *)&prcopt_.insopt.voopt.match.nms_n      },
    {"ins-vo-aid-nms-tau"    ,0,(void *)&prcopt_.insopt.voopt.match.nms_tau    },

    {"ins-vo-aid-k1",1,(void*)&prcopt_.insopt.voopt.cam.k1,},
    {"ins-vo-aid-k2",1,(void*)&prcopt_.insopt.voopt.cam.k2,},
    {"ins-vo-aid-p1",1,(void*)&prcopt_.insopt.voopt.cam.p1,},
    {"ins-vo-aid-p2",1,(void*)&prcopt_.insopt.voopt.cam.p2,},

    {"ins-vo-aid-lever1",1,(void*)&prcopt_.insopt.voopt.lbc[0]},
    {"ins-vo-aid-lever2",1,(void*)&prcopt_.insopt.voopt.lbc[1]},
    {"ins-vo-aid-lever3",1,(void*)&prcopt_.insopt.voopt.lbc[2]},

    {"ins-vo-aid-rpy1",1,(void*)&prcopt_.insopt.voopt.ebc[0]},
    {"ins-vo-aid-rpy2",1,(void*)&prcopt_.insopt.voopt.ebc[1]},
    {"ins-vo-aid-rpy3",1,(void*)&prcopt_.insopt.voopt.ebc[2]},

    {"ins-vo-aid-img-w",0,(void*)&prcopt_.insopt.voopt.match.img_w},
    {"ins-vo-aid-img-h",0,(void*)&prcopt_.insopt.voopt.match.img_h},

    {"",0,NULL,""}
};
/* discard space characters at tail ------------------------------------------*/
static void chop(char *str)
{
    char *p;
    if ((p=strchr(str,'#'))) *p='\0'; /* comment */
    for (p=str+strlen(str)-1;p>=str&&!isgraph((int)*p);p--) *p='\0';
}
/* enum to string ------------------------------------------------------------*/
static int enum2str(char *s, const char *comment, int val)
{
    char str[32],*p,*q,com[1024];
    int n;

    strcpy(com,comment);
    n=sprintf(str,"%d:",val);
    if (!(p=strstr(com,str))) {
        return sprintf(s,"%d",val);
    }
    if (!(q=strchr(p+n,','))&&!(q=strchr(p+n,')'))) {
        strcpy(s,p+n);
        return (int)strlen(p+n);
    }
    strncpy(s,p+n,q-p-n); s[q-p-n]='\0';
    return (int)(q-p-n);
}
/* string to enum ------------------------------------------------------------*/
static int str2enum(const char *str, const char *comment, int *val)
{
    const char *p;
    char s[32];
    
    for (p=comment;;p++) {
       if (!(p=strstr(p,str))) break;
       if (*(p-1)!=':') continue;
       for (p-=2;'0'<=*p&&*p<='9';p--) ;
       return sscanf(p+1,"%d",val)==1;
    }
    sprintf(s,"%30.30s:",str);
    if ((p=strstr(comment,s))) { /* number */
        return sscanf(p,"%d",val)==1;
    }
    return 0;
}
/* search option ---------------------------------------------------------------
* search option record
* args   : char   *name     I  option name
*          opt_t  *opts     I  options table
*                              (terminated with table[i].name="")
* return : option record (NULL: not found)
*-----------------------------------------------------------------------------*/
extern opt_t *searchopt(const char *name, const opt_t *opts)
{
    int i;
    
    trace(3,"searchopt: name=%s\n",name);
    
    for (i=0;*opts[i].name;i++) {
        if (strstr(opts[i].name,name)) return (opt_t *)(opts+i);
    }
    return NULL;
}
/* string to option value ------------------------------------------------------
* convert string to option value
* args   : opt_t  *opt      O  option
*          char   *str      I  option value string
* return : status (1:ok,0:error)
*-----------------------------------------------------------------------------*/
extern int str2opt(opt_t *opt, const char *str)
{
    switch (opt->format) {
        case 0: *(int    *)opt->var=atoi(str); break;
        case 1: *(double *)opt->var=atof(str); break;
        case 2: strcpy((char *)opt->var,str);  break;
        case 3: return str2enum(str,opt->comment,(int *)opt->var);
        default: return 0;
    }
    return 1;
}
/* option value to string ------------------------------------------------------
* convert option value to string
* args   : opt_t  *opt      I  option
*          char   *str      O  option value string
* return : length of output string
*-----------------------------------------------------------------------------*/
extern int opt2str(const opt_t *opt, char *str)
{
    char *p=str;
    
    trace(3,"opt2str : name=%s\n",opt->name);
    
    switch (opt->format) {
        case 0: p+=sprintf(p,"%d"   ,*(int   *)opt->var); break;
        case 1: p+=sprintf(p,"%.15g",*(double*)opt->var); break;
        case 2: p+=sprintf(p,"%s"   , (char  *)opt->var); break;
        case 3: p+=enum2str(p,opt->comment,*(int *)opt->var); break;
    }
    return (int)(p-str);
}
/* option to string -------------------------------------------------------------
* convert option to string (keyword=value # comment)
* args   : opt_t  *opt      I  option
*          char   *buff     O  option string
* return : length of output string
*-----------------------------------------------------------------------------*/
extern int opt2buf(const opt_t *opt, char *buff)
{
    char *p=buff;
    int n;
    
    trace(3,"opt2buf : name=%s\n",opt->name);
    
    p+=sprintf(p,"%-18s =",opt->name);
    p+=opt2str(opt,p);
    if (*opt->comment) {
        if ((n=(int)(buff+30-p))>0) p+=sprintf(p,"%*s",n,"");
        p+=sprintf(p," # (%s)",opt->comment);
    }
    return (int)(p-buff);
}
/* load options ----------------------------------------------------------------
* load options from file
* args   : char   *file     I  options file
*          opt_t  *opts     IO options table
*                              (terminated with table[i].name="")
* return : status (1:ok,0:error)
*-----------------------------------------------------------------------------*/
extern int loadopts(const char *file, opt_t *opts)
{
    FILE *fp;
    opt_t *opt;
    char buff[2048],*p;
    int n=0;
    
    trace(3,"loadopts: file=%s\n",file);
    
    if (!(fp=fopen(file,"r"))) {
        trace(1,"loadopts: options file open error (%s)\n",file);
        return 0;
    }
    while (fgets(buff,sizeof(buff),fp)) {
        n++;
        chop(buff);
        
        if (buff[0]=='\0') continue;
        
        if (!(p=strstr(buff,"="))) {
            fprintf(stderr,"invalid option %s (%s:%d)\n",buff,file,n);
            continue;
        }
        *p++='\0';
        chop(buff);
        if (!(opt=searchopt(buff,opts))) continue;
        
        if (!str2opt(opt,p)) {
            fprintf(stderr,"invalid option value %s (%s:%d)\n",buff,file,n);
            continue;
        }
    }
    fclose(fp);
    
    return 1;
}
/* save options to file --------------------------------------------------------
* save options to file
* args   : char   *file     I  options file
*          char   *mode     I  write mode ("w":overwrite,"a":append);
*          char   *comment  I  header comment (NULL: no comment)
*          opt_t  *opts     I  options table
*                              (terminated with table[i].name="")
* return : status (1:ok,0:error)
*-----------------------------------------------------------------------------*/
extern int saveopts(const char *file, const char *mode, const char *comment,
                    const opt_t *opts)
{
    FILE *fp;
    char buff[2048];
    int i;
    
    trace(3,"saveopts: file=%s mode=%s\n",file,mode);
    
    if (!(fp=fopen(file,mode))) {
        trace(1,"saveopts: options file open error (%s)\n",file);
        return 0;
    }
    if (comment) fprintf(fp,"# %s\n\n",comment);
    
    for (i=0;*opts[i].name;i++) {
        opt2buf(opts+i,buff);
        fprintf(fp,"%s\n",buff);
    }
    fclose(fp);
    return 1;
}
/* system options buffer to options ------------------------------------------*/
static void buff2sysopts(void)
{
    double pos[3],*rr;
    char buff[1024],*p,*id;
    int i,j,sat,*ps;
    
    prcopt_.elmin     =elmask_    *D2R;
    prcopt_.elmaskar  =elmaskar_  *D2R;
    prcopt_.elmaskhold=elmaskhold_*D2R;
    
    for (i=0;i<2;i++) {
        ps=i==0?&prcopt_.rovpos:&prcopt_.refpos;
        rr=i==0?prcopt_.ru:prcopt_.rb;
        
        if (antpostype_[i]==0) { /* lat/lon/hgt */
            *ps=0;
            pos[0]=antpos_[i][0]*D2R;
            pos[1]=antpos_[i][1]*D2R;
            pos[2]=antpos_[i][2];
            pos2ecef(pos,rr);
        }
        else if (antpostype_[i]==1) { /* xyz-ecef */
            *ps=0;
            rr[0]=antpos_[i][0];
            rr[1]=antpos_[i][1];
            rr[2]=antpos_[i][2];
        }
        else *ps=antpostype_[i]-1;
    }
    /* excluded satellites */
    for (i=0;i<MAXSAT;i++) prcopt_.exsats[i]=0;
    if (exsats_[0]!='\0') {
        strcpy(buff,exsats_);
        for (p=strtok(buff," ");p;p=strtok(NULL," ")) {
            if (*p=='+') id=p+1; else id=p;
            if (!(sat=satid2no(id))) continue;
            prcopt_.exsats[sat-1]=*p=='+'?2:1;
        }
    }
    /* snrmask */
    for (i=0;i<NFREQ;i++) {
        for (j=0;j<9;j++) prcopt_.snrmask.mask[i][j]=0.0;
        strcpy(buff,snrmask_[i]);
        for (p=strtok(buff,","),j=0;p&&j<9;p=strtok(NULL,",")) {
            prcopt_.snrmask.mask[i][j++]=atof(p);
        }
    }
    /* number of frequency (4:L1+L5) */
    if (prcopt_.nf==4) {
        prcopt_.nf=3;
        prcopt_.freqopt=1;
    }
}
/* options to system options buffer ------------------------------------------*/
static void sysopts2buff(void)
{
    double pos[3],*rr;
    char id[32],*p;
    int i,j,sat,*ps;
    
    elmask_    =prcopt_.elmin     *R2D;
    elmaskar_  =prcopt_.elmaskar  *R2D;
    elmaskhold_=prcopt_.elmaskhold*R2D;
    
    for (i=0;i<2;i++) {
        ps=i==0?&prcopt_.rovpos:&prcopt_.refpos;
        rr=i==0?prcopt_.ru:prcopt_.rb;
        
        if (*ps==0) {
            antpostype_[i]=0;
            ecef2pos(rr,pos);
            antpos_[i][0]=pos[0]*R2D;
            antpos_[i][1]=pos[1]*R2D;
            antpos_[i][2]=pos[2];
        }
        else antpostype_[i]=*ps+1;
    }
    /* excluded satellites */
    exsats_[0]='\0';
    for (sat=1,p=exsats_;sat<=MAXSAT&&p-exsats_<(int)sizeof(exsats_)-32;sat++) {
        if (prcopt_.exsats[sat-1]) {
            satno2id(sat,id);
            p+=sprintf(p,"%s%s%s",p==exsats_?"":" ",
                       prcopt_.exsats[sat-1]==2?"+":"",id);
        }
    }
    /* snrmask */
    for (i=0;i<NFREQ;i++) {
        snrmask_[i][0]='\0';
        p=snrmask_[i];
        for (j=0;j<9;j++) {
            p+=sprintf(p,"%s%.0f",j>0?",":"",prcopt_.snrmask.mask[i][j]);
        }
    }
    /* number of frequency (4:L1+L5) */
    if (prcopt_.nf==3&&prcopt_.freqopt==1) {
        prcopt_.nf=4;
        prcopt_.freqopt=0;
    }
}
/* reset system options to default ---------------------------------------------
* reset system options to default
* args   : none
* return : none
*-----------------------------------------------------------------------------*/
extern void resetsysopts(void)
{
    int i,j;
    
    trace(3,"resetsysopts:\n");
    
    prcopt_=prcopt_default;
    solopt_=solopt_default;
    filopt_.satantp[0]='\0';
    filopt_.rcvantp[0]='\0';
    filopt_.stapos [0]='\0';
    filopt_.geoid  [0]='\0';
    filopt_.dcb    [0]='\0';
    filopt_.blq    [0]='\0';
    filopt_.solstat[0]='\0';
    filopt_.trace  [0]='\0';
    for (i=0;i<2;i++) antpostype_[i]=0;
    elmask_=15.0;
    elmaskar_=0.0;
    elmaskhold_=0.0;
    for (i=0;i<2;i++) for (j=0;j<3;j++) {
        antpos_[i][j]=0.0;
    }
    exsats_[0] ='\0';
}
/* get system options ----------------------------------------------------------
* get system options
* args   : prcopt_t *popt   IO processing options (NULL: no output)
*          solopt_t *sopt   IO solution options   (NULL: no output)
*          folopt_t *fopt   IO file options       (NULL: no output)
* return : none
* notes  : to load system options, use loadopts() before calling the function
*-----------------------------------------------------------------------------*/
extern void getsysopts(prcopt_t *popt, solopt_t *sopt, filopt_t *fopt)
{
    trace(3,"getsysopts:\n");
    
    buff2sysopts();
    if (popt) *popt=prcopt_;
    if (sopt) *sopt=solopt_;
    if (fopt) *fopt=filopt_;
}
/* set system options ----------------------------------------------------------
* set system options
* args   : prcopt_t *prcopt I  processing options (NULL: default)
*          solopt_t *solopt I  solution options   (NULL: default)
*          filopt_t *filopt I  file options       (NULL: default)
* return : none
* notes  : to save system options, use saveopts() after calling the function
*-----------------------------------------------------------------------------*/
extern void setsysopts(const prcopt_t *prcopt, const solopt_t *solopt,
                       const filopt_t *filopt)
{
    trace(3,"setsysopts:\n");
    
    resetsysopts();
    if (prcopt) prcopt_=*prcopt;
    if (solopt) solopt_=*solopt;
    if (filopt) filopt_=*filopt;
    sysopts2buff();
}
/* rtk position settings------------------------------------------------------
 * args   : prcopt_t *prcopt I  processing options (NULL: default)
 *          solopt_t *solopt I  solution options   (NULL: default)
 *          filopt_t *filopt I  file options       (NULL: default)
 * return : none
 * notes  : to save system options, use saveopts() after calling the function
 * ---------------------------------------------------------------------------*/
extern void rtk_debug_opt(prcopt_t *prcopt_,solopt_t *solopt_,filopt_t *filopt_)
{
    trace(3,"rtk_debug_opt:\n");
}
