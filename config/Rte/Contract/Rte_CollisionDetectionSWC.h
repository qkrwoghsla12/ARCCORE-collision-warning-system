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
#ifndef RTE_COLLISIONDETECTIONSWC_H_
#define RTE_COLLISIONDETECTIONSWC_H_

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
#if defined(RTE_RUNNABLEAPI_CollisionDetection)
#define RTE_RUNNABLEAPI
#endif

/** --- Includes ----------------------------------------------------------------------------------
 * @req SWS_Rte_02751
 * @req SWS_Rte_07131
 */
#include <Rte_DataHandleType.h>
#include <Rte_CollisionDetectionSWC_Type.h>

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
    Rte_DE_IntImpl * const CollisionDetection_SonarRecv_distance;
    Rte_DE_LedStatusImpl * const CollisionDetection_FrontStatus_Status;
    Rte_DE_LedStatusImpl * const CollisionDetection_RearStatus_Status;
} Rte_CDS_CollisionDetectionSWC;

/** --- Instance handle type ---------------------------------------------------------------------- */
typedef Rte_CDS_CollisionDetectionSWC const * const Rte_Instance;

/** --- Singleton instance handle -----------------------------------------------------------------
 *  @req SWS_Rte_03793
 */
extern const Rte_Instance Rte_Inst_CollisionDetectionSWC;
#define self (Rte_Inst_CollisionDetectionSWC)

/** --- Calibration API --------------------------------------------------------------------------- */

/** --- Per Instance Memory API ------------------------------------------------------------------- */

/** --- Indirect port API ------------------------------------------------------------------------- */

/** --- Single Runnable APIs ---------------------------------------------------------------------- */
#if defined(RTE_RUNNABLEAPI)
/** --- CollisionDetection */
#if defined(RTE_RUNNABLEAPI_CollisionDetection)

void collisionDetection(void);

static inline IntImpl Rte_IRead_CollisionDetection_SonarRecv_distance(void) {
    return self->CollisionDetection_SonarRecv_distance->value;
}

static inline void Rte_IWrite_CollisionDetection_RearStatus_Status(/*IN*/LedStatusImpl value) {
    self->CollisionDetection_RearStatus_Status->value = value;
}

static inline void Rte_IWrite_CollisionDetection_FrontStatus_Status(/*IN*/LedStatusImpl value) {
    self->CollisionDetection_FrontStatus_Status->value = value;
}

#endif
#endif

/** --- All Runnable APIs ------------------------------------------------------------------------- */
#if !defined(RTE_RUNNABLEAPI)
void collisionDetection(void);

static inline IntImpl Rte_IRead_CollisionDetection_SonarRecv_distance(void) {
    return self->CollisionDetection_SonarRecv_distance->value;
}

static inline void Rte_IWrite_CollisionDetection_RearStatus_Status(/*IN*/LedStatusImpl value) {
    self->CollisionDetection_RearStatus_Status->value = value;
}

static inline void Rte_IWrite_CollisionDetection_FrontStatus_Status(/*IN*/LedStatusImpl value) {
    self->CollisionDetection_FrontStatus_Status->value = value;
}
#endif

/** === FOOTER ====================================================================================
 */

/** @req SWS_Rte_03710 */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_COLLISIONDETECTIONSWC_H_ */
