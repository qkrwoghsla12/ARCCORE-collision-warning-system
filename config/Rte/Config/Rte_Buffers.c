#include <Rte_Buffers.h>
#include <Rte_BswM_Type.h>
#include <Rte_CanTranslateSWC_Type.h>
#include <Rte_CollisionDetectionSWC_Type.h>
#include <Rte_ComM_Type.h>
#include <Rte_EcuM_Type.h>
#include <Rte_IoHwAb_Type.h>
#include <Rte_LEDActuatorSWC_Type.h>
#include <Rte_ModeManagerSWC_Type.h>
#include <Rte_UltraSonicSWC_Type.h>

/*lint -e451 AUTOSAR API SWS_MemMap_00003 */
/** === BswM Data =============================================================== */

#define BswM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <BswM_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

ComMModeEnum Rte_Buffer_bswM_modeRequestPort_SwcStartCommunication_requestedMode;
#define BswM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <BswM_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === CanTranslateSWC Data =============================================================== */

#define CanTranslateSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

IntImpl Rte_Buffer_cantranslateSWC_SonarRecv_distance;
#define CanTranslateSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === CollisionDetectionSWC Data =============================================================== */

#define CollisionDetectionSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

IntImpl Rte_Buffer_collisiondetectionSWC_SonarRecv_distance;
#define CollisionDetectionSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CollisionDetectionSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === ComM Data =============================================================== */

#define ComM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <ComM_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
ComM_ModeMachinesType ComM_ModeMachines;
#define ComM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <ComM_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === EcuM Data =============================================================== */

#define EcuM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <EcuM_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
EcuM_ModeMachinesType EcuM_ModeMachines;
#define EcuM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <EcuM_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === IoHwAb Data =============================================================== */

/** === LEDActuatorSWC Data =============================================================== */

#define LEDActuatorSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

LedStatusImpl Rte_Buffer_FrontLedSWC_Status_Status;
#define LEDActuatorSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LEDActuatorSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

LedStatusImpl Rte_Buffer_RearLedSWC_Status_Status;
#define LEDActuatorSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === ModeManagerSWC Data =============================================================== */

/** === UltraSonicSWC Data =============================================================== */

/** --- RTE Transformer Buffers ------------------------------------------------------------- */

#define Rte_START_SEC_CODE
#include <Rte_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_Internal_Init_Buffers(void) {
    // Init communication buffers

    // Init mode machine queues

}
#define Rte_STOP_SEC_CODE
#include <Rte_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

