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

#include "Rte_ModeManagerSWC.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ modeManagerInitSWC -----------------------------------------------------------------------
 */
void Rte_modeManagerInitSWC_Init(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define ModeManagerSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_ComMModeEnum ImplDE_modeManagerInitSWC_Init_ComMControl_requestedMode; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define ModeManagerSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define ModeManagerSWC_START_SEC_CONST_UNSPECIFIED
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_ModeManagerSWC ModeManagerSWC_modeManagerInitSWC = {
    .Init_ComMControl_requestedMode = &ImplDE_modeManagerInitSWC_Init_ComMControl_requestedMode
};
#define ModeManagerSWC_STOP_SEC_CONST_UNSPECIFIED
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define ModeManagerSWC_START_SEC_CONST_UNSPECIFIED
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_ModeManagerSWC = &ModeManagerSWC_modeManagerInitSWC;

#define ModeManagerSWC_STOP_SEC_CONST_UNSPECIFIED
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ modeManagerInitSWC -----------------------------------------------------------------------
 */

#define ModeManagerSWC_START_SEC_CODE
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_modeManagerInitSWC_Init(void) {

    /* PRE */

    /* MAIN */

    EcuModeManagerInit();

    /* POST */

    Rte_Write_ModeManagerSWC_modeManagerInitSWC_ComMControl_requestedMode(ImplDE_modeManagerInitSWC_Init_ComMControl_requestedMode.value); /*lint !e534 AUTOSAR API */

}
#define ModeManagerSWC_STOP_SEC_CODE
#include <ModeManagerSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

