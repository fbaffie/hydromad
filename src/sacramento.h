#ifndef _MODEL_SAC_H
#define _MODEL_SAC_H
/* THIS IS THE HEADER FILE WHERE SPECIFIC HEADER FILES
 * PROTOTYPES, STRUCTURES, AND FUNCTIONS ARE DEFINED */

/*  PROTOTYPE DEFINITIONS */
#define TIMESPERDAY 1

/* STRUCTURE DEFINITIONS */

struct SMA { /* I/O passed in function FLAND1 (THE SMA
              * accounting operation module */
  double uztwm,uzfwm,uzk,pctim,adimp,riva,zperc,rexp;   /* Parameters */
  double lztwm,lzfsm,lzfpm,lzsk,lzpk,pfree,rserv,side;  /* Parameters */
  double pxmlt,pemlt,mpemlt[12];                        /* Parameters */
  double etmin,etshp,etrng;                    /* et curve parameters */
  double uztwc,uzfwc,lztwc,lzfsc,lzfpc,adimc;               /* States */
  double dt,pxv,ep,epdist,tlci;                   /* Other Parameters */
  double tlci_flows[7];
};

struct FSUM1 { /* I/O passed in function FLAND1 (THE SMA
                * accounting operation module */
  double srot,simpvt,srodt,srost,sintft,sgwfp,sgwfs;
  double srecht,sett,se1,se3,se4,se5;
};


/* FUNCTION DECLARATION */
void sma_sac(double *P, double *E, int *n,
	     double *xpar, double *etmult,
	     double *dt, double *U);

void fland1(struct SMA *sma, struct FSUM1 *fsum1);


#endif
