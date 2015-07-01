/***************** INTERIORTHERMAL.H *********************** 
 *
 * Peter Driscoll 6/1/15
 *
 * This header file contains all the subroutines in
 * file interiorthermal.c.
 *
*/

// GLOBAL VARIABLE INDEXES
#define TMAN             20                    //index of TMAN variable.
#define TCORE            21                    //index of TCORE variable.

// UNITS CONSTANTS
#define KM               1d3       //[m] 1 km in m
//CONVERSIONS(for converting SI to cgs (swallow barf in mouth))
#define ERG_JOULE        1d7       //=erg/J
#define ERG_S_WATT       1d7       //=erg/s/W (W=J/s)
#define G_KG             1d3       //=g/kg
#define CM_M             1d2       //=cm/m
#define CM_KM            1d3*CM_M  //=cm/km
#define DENS_SI_CGS      G_KG/(CM_M)^3 //=(g/cm^3)/(kg/m^3) to convert SI to cgs.

// FUNDAMENTAL CONSTANTS
#define GASCONSTANT      8.3144621             //[J/mol/K] gas constant in SI units.      

// E MASS RESERVOIRS
#define EMASS            5.9742e24             //[kg] mass of E
#define EMASSFRACMAN     0.67                  //mass fraction of E mantle
#define EMASSMAN         EMASSFRACMAN*EMASS    //[kg] mass of E mantle
#define EMASSFRACCORE    0.32                  //mass frac E core
#define EMASSCORE        EMASSFRACCORE*EMASS   //[kg] mass of E core
#define EMASSIC          9.7d22                //[kg] mass of present IC.
#define EMASSOC          EMASSCORE-EMASSIC     //[kg] mass of present OC.
#define EMASSOCEAN       1.4d21                //[kg] mass of E oceans
#define EMASSFRACOCEAN   EMASSOCEAN/EMASS      //ocean mass frac
#define EMASSFRACCRUST   1-EMASSFRACMAN-EMASSFRACCORE-EMASSFRACOCEAN  //crust is remaining bit of mass.
#define EMASSCRUST       EMASSFRACCRUST*EMASS  //[kg] mass E crust today.

// INTERNAL STRUCTURE E
#define ERADIUS          6371.0*KM          //[m] radius of E.
#define ERMAN            6371.0*KM          //[m] radius of E mantle.
#define ERCORE           3481.0*KM          //[m] radius Core
#define ERICB            1221.0*KM          //[m] present day ICB radius.
#define EDMAN            ERADIUS-ERCORE     //[m] mantle shell thickness
#define EDOC             ERCORE-ERICB       //[m] present day core shell thickness
#define EVOL             4.0/3*PI*ERADIUS^3 //[m^3] volume of E.
#define EVOLIC           4.0/3*PI*ERICB^3   //[m^3] volume of present-day IC.
#define EVOLCORE         4.0/3*PI*ERCORE^3  //[m^3] volume of total core.
#define EVOLOC           EVOLCORE-EVOLIC    //[m^3] volume of OC today.
#define EVOLMAN          EVOL-EVOLCORE      //[m^3] volume of Mantle.
// DENSITIES - derived from mass and radius dfns.
#define EDENS            EMASS/EVOL         //[kg/m^3] density of E
#define EDENSMAN         EMASSMAN/EVOLMAN   //[kg/m^3] density of E mantle.
#define EDENSCORE        EMASSCORE/EVOLCORE //[kg/m^3] density of E core.
#define EDENSOC          EMASSOC/EVOLOC     //[kg/m^3] density of E core.
#define EDENSIC          EMASSIC/EVOLIC     //[kg/m^3] density of E IC.
#define DENSOCLE         700.0*DENS_SI_CGS  //[kg/m^3] density diff of OC light elements.
// Gravity
#define GRAVSURF         9.8                //[m/s2] Surf gravity in SI
#define GRAVUMAN         10.5               //[m/s2] UM gravity in SI
#define GRAVLMAN         10.5               //[m/s2] LM gravity in SI

/* THERMAL PROPERTIES */
#define SPECHEATMAN      1265.0             //[J/kg/K] specfic heat mantle.
#define SPECHEATCORE     840.0              //[J/kg/K] sp heat core.
#define THERMEXPANMAN    3d-5               //[K^-1] thermal expansivity of mantle.
#define THERMEXPANCORE   1d-5               //[K^-1] thermal expansivity of core.
#define THERMCONDUMAN    4.2                //[W/m/K] thermal conductivity of Upper mantle.
#define THERMCONDLMAN    10.0               //[W/m/K] thermal conductivity of Lower mantle.
#define THERMALDIFFUMAN  THERMALCONDUMAN/(EDENSMAN*SPECHEATMAN) //[m^2/s] thermal diffusivity mantle.
#define SPECLATENTICB    750d3              //[J/kg] specific latent heat release at ICB
#define SPECLATENTMAN    320d3              //[J/kg] specific latent heat release at ICB
/* CONVECTION CONSTANTS */
#define RAYLEIGHCRIT     660.          //[-] critical rayleigh number for spherical convection.
#define CONVEXPON        1./3          //[nd] convective cooling nusselt exponent "beta"
/* VISCOSITY PROPERTIES */
#define ACTVISCMAN       3d5           //[J/mol] viscosity activation energy mantle
#define ACTSHMODMAN      2d5           //[J/mol] shear modulus activation energy mantle
#define VISCREF          6d7           //[m2/s] reference kinematic mantle viscosity
#define VISCJUMPULM      2.            //[nd] viscosity jump from upper to lower mantle
#define SHMODREF_SI      6.24d4        //[Pa] reference kinematic mantle shear modulus
#define MELTB            2.5           //[nd] viscosity-melt reduction coefficient "B" (DB15 eq 8)
#define MELTPHISTAR      0.8           //[nd] viscosity-melt reduction coefficient "phi*" (DB15 eq 8)
#define MELTDELTA        6.0           //[nd] viscosity-melt reduction coefficient "delta" (DB15 eq 8)
#define MELTGAMMA        6.0           //[nd] viscosity-melt reduction coefficient "gamma" (DB15 eq 9)
#define MELTXI           5d-4          //[nd] viscosity-melt reduction coefficient "Xi" (DB15 eq 9)

/* TIDAL PROPERTIES */
#define STIFFNESS        1.71d4*1d9    //[Pa] effective stiffness of mantle (calibrated to k2=0.3, Q=100)
/* MELTING CONSTANTS */
#define ASOLIDUS         -1.160d-16    //[K/m3] mantle solidus coefficient Tsol(r)=A*r^3+B*r^2+C*r+D
#define BSOLIDUS         +1.708d-9     //[K/m2] B coefficient
#define CSOLIDUS         -9.074d-3     //[K/m] C coefficient
#define DSOLIDUS         +1.993d4      //[K] D coefficient
#define DTLIQMAN         +500.0        //[K] mantle liquidus offset, T_liq=T_sol+DTLIQMAN
#define DVLIQDTM         +8d17         //[m3/K] change in mantle liquid volume with T_m approximated (Driscoll&B 2015)
#define DLIND            7000.0*KM     //[m] lindemann's law length scale for iron liquidus "D_Fe" (DB15 A23)
#define TREFLIND         5600.0        //[K] lindemann's law reference temp. "T_Fe0" (DB15 A23)
/* ADIABATIC PROPERTIES */
#define ADGRADMAN        0.5/KM        //[K/m] mantle linear adiabatic gradient =0.5K/km  (DB15 eq A18)
#define DADCORE          6340.0*KM     //[m] liq iron core adiabatic length scale (DB15 eq A22)
#define GRUNEISEN        1.3           //[nd] core gruneisen parameter
#define ADJUMPM2UM       0.7           //[nd] adiabatic temp jump from ave mantle to UM. "epsilon_UM"
#define ADJUMPM2LM       1.3           //[nd] adiabatic temp jump from ave mantle to LM. "epsilon_LM"
#define ADJUMPC2CMB      0.8           //[nd] adiabatic temp jump from ave core to CMB. "epsilon_c"
/* MAGNETIC DYNAMO PROPERTIES */
#define MAGPERM          4*PI*1d-7                //[H/m] magnetic permeability constant in SI units.
#define GAMMADIPOLE      0.2                      //[nd] saturation constant for fast rot dipolar dynamos (OC2006)
#define ELECCONDCORE     10d5                     //[S/m]  electrical conductivity of core.  How does this convert to cgs??
#define LORENTZNUM       2.5d-8                   //[W Ohm/K] lorentz number, relates thermal and electrical conductivity.        

void InitializeControlInteriorthermal(CONTROL*);
void AddModuleInteriorthermal(MODULE*,int,int);
void BodyCopyInteriorthermal(BODY*,BODY*,int,int);
void InitializeBodyEqtide(BODY*,CONTROL*,UPDATE*,int,int);
void InitializeUpdateTmpBodyInteriorthermal(BODY*,CONTROL*,UPDATE*,int);

/* Options Info */

#define OPTSTARTINTERIORTHERMAL         1200 /* Start of INTERIORTHERMAL options */
#define OPTENDINTERIORTHERMAL           1400 /* End of INTERIORTHERMAL options */

/* Scalar Properties */
#define OPT_TMAN            1210   //Temperature Mantle AVE
#define OPT_TCORE           1211   //Temperature Core AVE
#define OPT_TBLUMAN         1212   //UM TBL thickness
#define OPT_TBLLMAN         1213   //LM TBL thickness
#define OPT_TJUMPUMAN       1214   //Temperature Jump across UMTBL
#define OPT_TJUMPLMAN       1215   //Temperature Jump across LMTBL
#define OPT_VISCUMAN        1220   //Viscosity UMTBL
#define OPT_VISCLMAN        1221   //Viscosity LMTBL
#define OPT_SHMODUMAN       1222   //Shear modulus UMTBL
#define OPT_SHMODLMAN       1223   //Shear modulus LMTBL
#define OPT_FMELTUMAN       1224   //Melt fraction UMTBL
#define OPT_FMELTLMAN       1225   //Melt fraction LMTBL
#define OPT_LOVE2MAN        1226   //Mantle k2 love number
#define OPT_IMLOVE2MAN      1227   //Mantle Im(k2) love number
/* Time Derivatives & Gradients */
#define OPT_TDOTMAN         1232   //Time deriv of mean mantle temp
#define OPT_TDOTCORE        1233   //time deriv of mean core temp
#define OPT_HFLUXUMAN       1234   //hflux upper mantle thermal boundary layer (UMTBL)
#define OPT_HFLOWUMAN       1235   //hflow UMTBL
#define OPT_HFLUXCMB        1237   //hflux lower mantle TBL = CMB
#define OPT_HFLOWCMB        1238   //hflow LMTBL=CMB
#define OPT_HFLOWTIDALMAN   1242   //hflow tidal dissipation in mantle
#define OPT_HFLOWTIDALCORE  1243   //hflow tidal dissipation in core
#define OPT_HFLOWLATENTMAN  1244   //latent hflow from solidification of mantle
#define OPT_HFLOWLATENTIC   1250   //latent hflow from solidification of IC
#define OPT_HFLOWICB        1251   //hflow across ICB
#define OPT_HFLUXSURF       1260   //hflux surface of mantle
#define OPT_HFLOWSURF       1261   //hflow surface of mantle
/* Core Variables */
#define OPT_RIC             1270   //IC radius
#define OPT_DOC             1271   //OC shell thickness
#define OPT_CHIOC           1280   //OC light element concentration chi.
#define OPT_CHIIC           1281   //IC light element concentration chi.
#define OPT_THERMCONDUCTOC  1282   //Thermal conductivity OC
#define OPT_THERMCONDUCTIC  1283   //Thermal conductivity IC

#define OPT_HALTMINTMAN     1290
#define OPT_HALTMINTCORE    1291

/* Options Functions */
void HelpOptionsInteriorthermal(OPTIONS*);
void ReadTMan(BODY*,CONTROL*,FILES*,OPTIONS*,SYSTEM*,int) ;
void ReadTCore(BODY*,CONTROL*,FILES*,OPTIONS*,SYSTEM*,int) ;

void ReadHaltMinTMan(BODY*,CONTROL*,FILES*,OPTIONS*,SYSTEM*,int);
void ReadHaltMinTCore(BODY*,CONTROL*,FILES*,OPTIONS*,SYSTEM*,int);

void InitializeOptionsInteriorthermal(OPTIONS*,fnReadOption[]);
void ReadOptionsInteriorthermal(BODY*,CONTROL*,FILES*,OPTIONS*,SYSTEM*,fnReadOption[],int);

/* Halt Functions */
#define INTERIORTHERMALHALTSYSEND       6
#define INTERIORTHERMALHALTBODYEND      6

int fbHaltMinTMan(BODY*,EVOLVE*,HALT*,IO*,UPDATE*,int);  //syntax now is same as fnHaltModule in vplanet.h
int fbHaltMinTCore(BODY*,EVOLVE*,HALT*,IO*,UPDATE*,int);
void CountHaltsInteriorthermal(HALT*,int*);

/* Verify Functions */

void VerifyInteriorthermal(BODY*,CONTROL*,FILES*,OPTIONS*,OUTPUT*,SYSTEM*,UPDATE*,fnUpdateVariable***,int,int);
void VerifyRotationInteriorthermal(BODY*,CONTROL*,OPTIONS*,char[],int);
void InitializeVplanetInteriorthermal(CONTROL*,MODULE*);
void PropertiesInteriorthermal(BODY*,int);
void VerifyHaltInteriorthermal(BODY*,CONTROL*,OPTIONS*,int,int*);
void VerifyRotationInteriorthermal(BODY*,CONTROL*,OPTIONS*,char[],int);

/* Update functions */
void InitializeUpdateInteriorthermal(BODY*,UPDATE*,int);
void FinalizeUpdateEccInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdate40KNumManInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdate232ThNumManInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdate238UNumManInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdate235UNumManInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdateOblInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdateRotInteriorthermal(BODY*,UPDATE*,int*,int,int);
void FinalizeUpdateSemiInteriorthermal(BODY*,UPDATE*,int*,int,int);

/* Output Functinos */

/* INTERIORTHERMAL */
#define OUTSTARTINTERIORTHERMAL         1200
#define OUTENDINTERIORTHERMAL           1400

/* Output Body Properties */
/* Scalar Properties */
#define OUT_TMAN            1210   //Temperature Mantle AVE
#define OUT_TCORE           1211   //Temperature Core AVE
#define OUT_TBLUMAN         1212   //UM TBL thickness
#define OUT_TBLLMAN         1213   //LM TBL thickness
#define OUT_TJUMPUMAN       1214   //Temperature Jump across UMTBL
#define OUT_TJUMPLMAN       1215   //Temperature Jump across LMTBL
#define OUT_VISCUMAN        1220   //Viscosity UMTBL
#define OUT_VISCLMAN        1221   //Viscosity LMTBL
#define OUT_SHMODUMAN       1222   //Shear modulus UMTBL
#define OUT_SHMODLMAN       1223   //Shear modulus LMTBL
#define OUT_FMELTUMAN       1224   //Melt fraction UMTBL
#define OUT_FMELTLMAN       1225   //Melt fraction LMTBL
#define OUT_LOVE2MAN        1226   //Mantle k2 love number
#define OUT_IMLOVE2MAN      1227   //Mantle Im(k2) love number
/* Time Derivatives & Gradients */
#define OUT_TDOTMAN         1232   //Time deriv of mean mantle temp
#define OUT_TDOTCORE        1233   //time deriv of mean core temp
#define OUT_HFLUXUMAN       1234   //hflux upper mantle thermal boundary layer (UMTBL)
#define OUT_HFLOWUMAN       1235   //hflow UMTBL
#define OUT_HFLUXCMB        1237   //hflux lower mantle TBL = CMB
#define OUT_HFLOWCMB        1238   //hflow LMTBL=CMB
#define OUT_HFLOWTIDALMAN   1242   //hflow tidal dissipation in mantle
#define OUT_HFLOWTIDALCORE  1243   //hflow tidal dissipation in core
#define OUT_HFLOWLATENTMAN  1244   //latent hflow from solidification of mantle
#define OUT_HFLOWLATENTIC   1250   //latent hflow from solidification of IC
#define OUT_HFLOWICB        1251   //hflow across ICB
#define OUT_HFLUXSURF       1260   //hflux surface of mantle
#define OUT_HFLOWSURF       1261   //hflow surface of mantle
/* Core Variables */
#define OUT_RIC             1270   //IC radius
#define OUT_DOC             1271   //OC shell thickness
#define OUT_CHIOC           1280   //OC light element concentration chi.
#define OUT_CHIIC           1281   //IC light element concentration chi.
#define OUT_THERMCONDUCTOC  1282   //Thermal conductivity OC
#define OUT_THERMCONDUCTIC  1283   //Thermal conductivity IC


void HelpOutputInteriorthermal(OUTPUT*);
void InitializeOutputInteriorthermal(OUTPUT*,fnWriteOutput[]);
void InitializeOutputFunctionInteriorthermal(OUTPUT*,int,int);
void FinalizeOutputFunctionInteriorthermal(OUTPUT*,int,int);

void WriteTMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteTCore(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteTDotMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteTDotCore(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHfluxUMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowUMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHfluxLMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowLMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowTidalMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowTidalCore(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowLatentMan(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowLatentIC(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowICB(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteHflowSurf(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteRIC(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteChiOC(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);

/* Logging Functions */
void LogOptionsInteriorthermal(CONTROL*,FILE*);
void LogInteriorthermal(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UPDATE*,fnWriteOutput[],FILE*);
void LogBodyInteriorthermal(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UPDATE*,fnWriteOutput[],FILE*,int);

/* Thermal Functions */
double fdTDotMan(BODY*,SYSTEM*,int*,int);
double fdTDotCore(BODY*,SYSTEM*,int*,int);
double fdThickBLUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdThickBLLMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdDTempUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdDTempLMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHfluxUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHfluxCMB(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHflowUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHflowLatentMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHflowCMB(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHflowMeltMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdPowerTidalMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdHflowSurfMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdImLove2Man(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdLove2Man(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdViscUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdViscLMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdShmodMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdFmeltUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdTsolUMan(BODY*,SYSTEM*,UPDATE *update,int,int);
double fdTliqUMan(BODY*,SYSTEM*,UPDATE *update,int,int);

void fnForceBehaviorInteriorthermal(BODY*,EVOLVE*,IO*,int,int);
