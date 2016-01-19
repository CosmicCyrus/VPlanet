/***************** BINARY.H *********************** 
 *
 * David Fleming (dflemin3), Tue Jan 12 10:23am PDT 2016
 *
 * This header file contains all the subroutines in
 * file binary.c.
 *
*/

#define TOMASS                  1.39e21     // Mass of one terrestrial ocean in kg (TO)
#define TOHMASS                 TOMASS/9.   // Hydrogen mass in one TO

void InitializeModuleBinary(CONTROL *control,MODULE *module);
void InitializeControlBinary(CONTROL*);
void AddModuleBinary(MODULE*,int,int);
void BodyCopyAtmEsc(BODY*,BODY*,int,int);
void InitializeBodyBinary(BODY*,CONTROL*,UPDATE*,int,int);
void InitializeUpdateTmpBodyBinary(BODY*,CONTROL*,UPDATE*,int);

/* Options Info */
#define OPTSTARTATMESC          1200 /* Start of AtmEsc options */
#define OPTENDATMESC            1300 /* End of AtmEsc options */

#define OPT_SURFACEWATERMASS    1210 // Initial surface water mass
#define OPT_HALTDESICCATED      1211 // Halt if desiccated?
#define OPT_MINSURFACEWATERMASS 1212 // Minimum surface water mass (desiccated below this)
#define OPT_XFRAC               1213 // X-ray absorption radius as a fraction of planet radius
#define OPT_ATMXABSEFF          1214 // Absorption efficiency (epsilon)
#define OPT_ENVELOPEMASS        1215 // Initial envelope mass
#define OPT_HALTENVELOPEGONE    1216 // Halt if evaporated?
#define OPT_MINENVELOPEMASS     1217 // Minimum envelope mass (evaporated below this)

/* Options Functions */
void HelpOptionsAtmEsc(OPTIONS*);
void InitializeOptionsAtmEsc(OPTIONS*,fnReadOption[]);
void ReadOptionsAtmEsc(BODY*,CONTROL*,FILES*,OPTIONS*,SYSTEM*,fnReadOption[],int);

/* Halt Functions */
#define ATMESCHALTSYSEND       5
#define ATMESCHALTBODYEND      5

int fbHaltSurfaceDesiccated(BODY*,EVOLVE*,HALT*,IO*,UPDATE*,int);
int fbHaltEnvelopeGone(BODY*,EVOLVE*,HALT*,IO*,UPDATE*,int);
void CountHaltsAtmEsc(HALT*,int*);

/* Verify Functions */
void VerifyAtmEsc(BODY*,CONTROL*,FILES*,OPTIONS*,OUTPUT*,SYSTEM*,UPDATE*,fnUpdateVariable***,int,int);
void VerifyRotationBinary(BODY*,CONTROL*,OPTIONS*,char[],int);
void InitializeVplanetAtmEsc(CONTROL*,MODULE*);
void PropertiesAtmEsc(BODY*,int);
void VerifyHaltAtmEsc(BODY*,CONTROL*,OPTIONS*,int,int*);
void VerifyRotationAtmEsc(BODY*,CONTROL*,OPTIONS*,char[],int);

/* Update functions */
void InitializeUpdateAtmEsc(BODY*,UPDATE*,int);
void FinalizeUpdateEccBinary(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateNumIsotopeAtmEsc(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateOblBinary(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateRotBinary(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateSemiBinary(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateSurfaceWaterMassAtmEsc(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateEnvelopeMassAtmEsc(BODY*,UPDATE*,int*,int,int,int);
void FinalizeUpdateMassAtmEsc(BODY*,UPDATE*,int*,int,int,int);

/* Output Functinos */

/* AtmEsc 1200 - 1299 */
#define OUTSTARTATMESC         1200
#define OUTENDATMESC           1300

/* Body Properties due to atmospheric escape */
#define OUT_SURFACEWATERMASS	 1210
#define OUT_ENVELOPEMASS	     1211

void HelpOutputAtmEsc(OUTPUT*);
void InitializeOutputAtmEsc(OUTPUT*,fnWriteOutput[]);
void InitializeOutputFunctionAtmEsc(OUTPUT*,int,int);
void FinalizeOutputFunctionAtmEsc(OUTPUT*,int,int);

void WriteSurfaceWaterMass(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);
void WriteEnvelopeMass(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UNITS*,UPDATE*,int,double*,char[]);


/* Logging Functions */
void LogOptionsBinary(CONTROL*,FILE*);
void LogBinary(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UPDATE*,fnWriteOutput[],FILE*);
void LogBodyAtmEsc(BODY*,CONTROL*,OUTPUT*,SYSTEM*,UPDATE*,fnWriteOutput[],FILE*,int);

/* AtmEsc functions */
void fnForceBehaviorAtmEsc(BODY*,EVOLVE*,IO*,SYSTEM*,UPDATE*,int,int);
double fdDSurfaceWaterMassDt(BODY*,SYSTEM*,int*);
double fdDEnvelopeMassDt(BODY*,SYSTEM*,int*);

/* Dummy functions */
double fdSurfEnFluxAtmEsc(BODY*,SYSTEM*,UPDATE*,int,int);
