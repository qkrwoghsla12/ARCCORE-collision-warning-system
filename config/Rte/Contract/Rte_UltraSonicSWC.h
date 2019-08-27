/**
 * Application Header File
 *
 * @req SWS_Rte_01003
 */

/** === HEADER ====================================================================================
 */
/*lint -e18 -e452 LINT:OTHER:Duplicate declarations hidden behind ifdef */

/** --- Normal include guard ----------------------------------------------------------------------
 */
#ifndef RTE_ULTRASONICSWC_H_
#define RTE_ULTRASONICSWC_H_

/** --- C++ guard ---------------------------------------------------------------------------------
 * @req SWS_Rte_03709
 */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --- Duplicate application include guard -------------------------------------------------------
 * @req SWS_Rte_01006
 */
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif
#define RTE_APPLICATION_HEADER_FILE

/** --- Single runnable API -----------------------------------------------------------------------
 * @req SWS_Rte_02751
 */
#if defined(RTE_RUNNABLEAPI_UltraSonic)
#define RTE_RUNNABLEAPI
#endif

/** --- Includes ----------------------------------------------------------------------------------
 * @req SWS_Rte_02751
 * @req SWS_Rte_07131
 */
#include <Rte_DataHandleType.h>
#include <Rte_UltraSonicSWC_Type.h>

/** --- Application Errors ------------------------------------------------------------------------
 * @req SWS_Rte_02575
 * @req SWS_Rte_02576
 * @req SWS_Rte_07143
 */
#define RTE_E_DigitalServiceRead_E_NOT_OK 1U
#define RTE_E_DigitalServiceRead_E_OK 0U
#define RTE_E_DigitalServiceWrite_E_NOT_OK 1U
#define RTE_E_DigitalServiceWrite_E_OK 0U

/** --- Initial Values ----------------------------------------------------------------------------
 * @SWS_Rte_05078
 */

/** --- PIM DATA TYPES ------------------------------------------------------------------------------ */

/** --- Condition Value Macros -------------------------------------------------------
 * @req SWS_Rte_03854
 */

/** === BODY ======================================================================================
 */

/** @req SWS_Rte_03731
 *  @req SWS_Rte_07137
 *  @req SWS_Rte_07138
 *  !req SWS_Rte_06523
 *  @req SWS_Rte_03730
 *  @req SWS_Rte_07677
 *  @req SWS_Rte_02620
 *  @req SWS_Rte_02621
 *  @req SWS_Rte_01055
 *  @req SWS_Rte_03726 */

/** @req SWS_Rte_01343
 *  @req SWS_Rte_01342
 *  !req SWS_Rte_06524
 *  @req SWS_Rte_01053
 */

extern Std_ReturnType Rte_Call_UltraSonicSWC_ultrasonicSWC_SonarTrig_Write(/*IN*/DigitalLevel Level);
extern Std_ReturnType Rte_Call_UltraSonicSWC_ultrasonicSWC_SonarEcho_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality);

/** @req SWS_Rte_07132
 *  @req SWS_Rte_03714 
 *  @req SWS_Rte_03725 
 *  @req SWS_Rte_03752
 *  @req SWS_Rte_02623
 */
typedef struct {
    Rte_DE_IntImpl * const UltraSonic_SonarSend_distance;
} Rte_CDS_UltraSonicSWC;

/** --- Instance handle type ---------------------------------------------------------------------- */
typedef Rte_CDS_UltraSonicSWC const * const Rte_Instance;

/** --- Singleton instance handle -----------------------------------------------------------------
 *  @req SWS_Rte_03793
 */
extern const Rte_Instance Rte_Inst_UltraSonicSWC;
#define self (Rte_Inst_UltraSonicSWC)

/** --- Calibration API --------------------------------------------------------------------------- */

/** --- Per Instance Memory API ------------------------------------------------------------------- */

/** --- Indirect port API ------------------------------------------------------------------------- */

/** --- Single Runnable APIs ---------------------------------------------------------------------- */
#if defined(RTE_RUNNABLEAPI)
/** --- UltraSonic */
#if defined(RTE_RUNNABLEAPI_UltraSonic)

void UltraSonic(void);

static inline void Rte_IWrite_UltraSonic_SonarSend_distance(/*IN*/IntImpl value) {
    self->UltraSonic_SonarSend_distance->value = value;
}

static inline Std_ReturnType Rte_Call_SonarTrig_Write(/*IN*/DigitalLevel Level) {
    return Rte_Call_UltraSonicSWC_ultrasonicSWC_SonarTrig_Write(Level);
}

static inline Std_ReturnType Rte_Call_SonarEcho_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality) {
    return Rte_Call_UltraSonicSWC_ultrasonicSWC_SonarEcho_Read(Level, Quality);
}

#endif
#endif

/** --- All Runnable APIs ------------------------------------------------------------------------- */
#if !defined(RTE_RUNNABLEAPI)
void UltraSonic(void);

static inline void Rte_IWrite_UltraSonic_SonarSend_distance(/*IN*/IntImpl value) {
    self->UltraSonic_SonarSend_distance->value = value;
}

static inline Std_ReturnType Rte_Call_SonarTrig_Write(/*IN*/DigitalLevel Level) {
    return Rte_Call_UltraSonicSWC_ultrasonicSWC_SonarTrig_Write(Level);
}

static inline Std_ReturnType Rte_Call_SonarEcho_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality) {
    return Rte_Call_UltraSonicSWC_ultrasonicSWC_SonarEcho_Read(Level, Quality);
}
#endif

/** === FOOTER ====================================================================================
 */

/** @req SWS_Rte_03710 */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_ULTRASONICSWC_H_ */
