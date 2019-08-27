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
#ifndef RTE_CANTRANSLATESWC_H_
#define RTE_CANTRANSLATESWC_H_

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
#if defined(RTE_RUNNABLEAPI_CanTranslate)
#define RTE_RUNNABLEAPI
#endif

/** --- Includes ----------------------------------------------------------------------------------
 * @req SWS_Rte_02751
 * @req SWS_Rte_07131
 */
#include <Rte_DataHandleType.h>
#include <Rte_CanTranslateSWC_Type.h>

/** --- Application Errors ------------------------------------------------------------------------
 * @req SWS_Rte_02575
 * @req SWS_Rte_02576
 * @req SWS_Rte_07143
 */

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

/** @req SWS_Rte_07132
 *  @req SWS_Rte_03714 
 *  @req SWS_Rte_03725 
 *  @req SWS_Rte_03752
 *  @req SWS_Rte_02623
 */
typedef struct {
    Rte_DE_IntImpl * const CanTranslate_CanRxPort_message;
    Rte_DE_IntImpl * const CanTranslate_SonarRecv_distance;
    Rte_DE_IntImpl * const CanTranslate_CanTxPort_message;
} Rte_CDS_CanTranslateSWC;

/** --- Instance handle type ---------------------------------------------------------------------- */
typedef Rte_CDS_CanTranslateSWC const * const Rte_Instance;

/** --- Singleton instance handle -----------------------------------------------------------------
 *  @req SWS_Rte_03793
 */
extern const Rte_Instance Rte_Inst_CanTranslateSWC;
#define self (Rte_Inst_CanTranslateSWC)

/** --- Calibration API --------------------------------------------------------------------------- */

/** --- Per Instance Memory API ------------------------------------------------------------------- */

/** --- Indirect port API ------------------------------------------------------------------------- */

/** --- Single Runnable APIs ---------------------------------------------------------------------- */
#if defined(RTE_RUNNABLEAPI)
/** --- CanTranslate */
#if defined(RTE_RUNNABLEAPI_CanTranslate)

void canTranslate(void);

static inline IntImpl Rte_IRead_CanTranslate_SonarRecv_distance(void) {
    return self->CanTranslate_SonarRecv_distance->value;
}

static inline IntImpl Rte_IRead_CanTranslate_CanRxPort_message(void) {
    return self->CanTranslate_CanRxPort_message->value;
}

static inline void Rte_IWrite_CanTranslate_CanTxPort_message(/*IN*/IntImpl value) {
    self->CanTranslate_CanTxPort_message->value = value;
}

#endif
#endif

/** --- All Runnable APIs ------------------------------------------------------------------------- */
#if !defined(RTE_RUNNABLEAPI)
void canTranslate(void);

static inline IntImpl Rte_IRead_CanTranslate_SonarRecv_distance(void) {
    return self->CanTranslate_SonarRecv_distance->value;
}

static inline IntImpl Rte_IRead_CanTranslate_CanRxPort_message(void) {
    return self->CanTranslate_CanRxPort_message->value;
}

static inline void Rte_IWrite_CanTranslate_CanTxPort_message(/*IN*/IntImpl value) {
    self->CanTranslate_CanTxPort_message->value = value;
}
#endif

/** === FOOTER ====================================================================================
 */

/** @req SWS_Rte_03710 */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_CANTRANSLATESWC_H_ */
