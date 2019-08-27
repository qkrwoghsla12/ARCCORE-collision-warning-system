/** === HEADER ====================================================================================
 */

#include <Rte.h>

#include <Os.h>
#if ((OS_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION))
#error Os version mismatch
#endif

#include <Com.h>
#if ((COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || (COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION))
#error Com version mismatch
#endif

#include <Rte_Hook.h>
#include <Rte_Internal.h>
#include <Rte_Calprms.h>

#include "Rte_CollisionDetectionSWC.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ collisiondetectionSWC -----------------------------------------------------------------------
 */
void Rte_collisiondetectionSWC_CollisionDetection(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define CollisionDetectionSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_LedStatusImpl ImplDE_collisiondetectionSWC_CollisionDetection_FrontStatus_Status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define CollisionDetectionSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define CollisionDetectionSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_LedStatusImpl ImplDE_collisiondetectionSWC_CollisionDetection_RearStatus_Status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define CollisionDetectionSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define CollisionDetectionSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_collisiondetectionSWC_CollisionDetection_SonarRecv_distance; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define CollisionDetectionSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define CollisionDetectionSWC_START_SEC_CONST_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_CollisionDetectionSWC CollisionDetectionSWC_collisiondetectionSWC = {
    .CollisionDetection_SonarRecv_distance = &ImplDE_collisiondetectionSWC_CollisionDetection_SonarRecv_distance,
    .CollisionDetection_RearStatus_Status = &ImplDE_collisiondetectionSWC_CollisionDetection_RearStatus_Status,
    .CollisionDetection_FrontStatus_Status = &ImplDE_collisiondetectionSWC_CollisionDetection_FrontStatus_Status
};
#define CollisionDetectionSWC_STOP_SEC_CONST_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define CollisionDetectionSWC_START_SEC_CONST_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_CollisionDetectionSWC = &CollisionDetectionSWC_collisiondetectionSWC;

#define CollisionDetectionSWC_STOP_SEC_CONST_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ collisiondetectionSWC -----------------------------------------------------------------------
 */

#define CollisionDetectionSWC_START_SEC_CODE
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_collisiondetectionSWC_CollisionDetection(void) {

    /* PRE */
    Rte_Read_CollisionDetectionSWC_collisiondetectionSWC_SonarRecv_distance(
            &ImplDE_collisiondetectionSWC_CollisionDetection_SonarRecv_distance.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    collisionDetection();

    /* POST */

    Rte_Write_CollisionDetectionSWC_collisiondetectionSWC_RearStatus_Status(ImplDE_collisiondetectionSWC_CollisionDetection_RearStatus_Status.value); /*lint !e534 AUTOSAR API */

    Rte_Write_CollisionDetectionSWC_collisiondetectionSWC_FrontStatus_Status(
            ImplDE_collisiondetectionSWC_CollisionDetection_FrontStatus_Status.value); /*lint !e534 AUTOSAR API */

}
#define CollisionDetectionSWC_STOP_SEC_CODE
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

