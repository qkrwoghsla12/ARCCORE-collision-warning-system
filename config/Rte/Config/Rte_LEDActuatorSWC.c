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

#include "Rte_LEDActuatorSWC.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ FrontLedSWC -----------------------------------------------------------------------
 */
void Rte_FrontLedSWC_LEDActuator(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */
/** ------ RearLedSWC -----------------------------------------------------------------------
 */
void Rte_RearLedSWC_LEDActuator(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define LEDActuatorSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_LedStatusImpl ImplDE_FrontLedSWC_LEDActuator_Status_Status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define LEDActuatorSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LEDActuatorSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_LedStatusImpl ImplDE_RearLedSWC_LEDActuator_Status_Status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define LEDActuatorSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define LEDActuatorSWC_START_SEC_CONST_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_LEDActuatorSWC LEDActuatorSWC_FrontLedSWC = {
    .LEDActuator_Status_Status = &ImplDE_FrontLedSWC_LEDActuator_Status_Status,
    .DigitalLED = {
        .Call_Write = Rte_Call_LEDActuatorSWC_FrontLedSWC_DigitalLED_Write
    }
};
#define LEDActuatorSWC_STOP_SEC_CONST_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LEDActuatorSWC_START_SEC_CONST_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_LEDActuatorSWC LEDActuatorSWC_RearLedSWC = {
    .LEDActuator_Status_Status = &ImplDE_RearLedSWC_LEDActuator_Status_Status,
    .DigitalLED = {
        .Call_Write = Rte_Call_LEDActuatorSWC_RearLedSWC_DigitalLED_Write
    }
};
#define LEDActuatorSWC_STOP_SEC_CONST_UNSPECIFIED
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ FrontLedSWC -----------------------------------------------------------------------
 */

#define LEDActuatorSWC_START_SEC_CODE
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_FrontLedSWC_LEDActuator(void) {

    Rte_Instance self = &LEDActuatorSWC_FrontLedSWC;
    /* PRE */
    Rte_Read_LEDActuatorSWC_FrontLedSWC_Status_Status(&ImplDE_FrontLedSWC_LEDActuator_Status_Status.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    ledActuator(self);

    /* POST */

}
#define LEDActuatorSWC_STOP_SEC_CODE
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

/** ------ RearLedSWC -----------------------------------------------------------------------
 */

#define LEDActuatorSWC_START_SEC_CODE
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_RearLedSWC_LEDActuator(void) {

    Rte_Instance self = &LEDActuatorSWC_RearLedSWC;
    /* PRE */
    Rte_Read_LEDActuatorSWC_RearLedSWC_Status_Status(&ImplDE_RearLedSWC_LEDActuator_Status_Status.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    ledActuator(self);

    /* POST */

}
#define LEDActuatorSWC_STOP_SEC_CODE
#include <LEDActuatorSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

