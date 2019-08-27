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

#include "Rte_UltraSonicSWC.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ ultrasonicSWC -----------------------------------------------------------------------
 */
void Rte_ultrasonicSWC_UltraSonic(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define UltraSonicSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_ultrasonicSWC_UltraSonic_SonarSend_distance; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define UltraSonicSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define UltraSonicSWC_START_SEC_CONST_UNSPECIFIED
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_UltraSonicSWC UltraSonicSWC_ultrasonicSWC = {
    .UltraSonic_SonarSend_distance = &ImplDE_ultrasonicSWC_UltraSonic_SonarSend_distance
};
#define UltraSonicSWC_STOP_SEC_CONST_UNSPECIFIED
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define UltraSonicSWC_START_SEC_CONST_UNSPECIFIED
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_UltraSonicSWC = &UltraSonicSWC_ultrasonicSWC;

#define UltraSonicSWC_STOP_SEC_CONST_UNSPECIFIED
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ ultrasonicSWC -----------------------------------------------------------------------
 */

#define UltraSonicSWC_START_SEC_CODE
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_ultrasonicSWC_UltraSonic(void) {

    /* PRE */

    /* MAIN */

    UltraSonic();

    /* POST */

    Rte_Write_UltraSonicSWC_ultrasonicSWC_SonarSend_distance(ImplDE_ultrasonicSWC_UltraSonic_SonarSend_distance.value); /*lint !e534 AUTOSAR API */

}
#define UltraSonicSWC_STOP_SEC_CODE
#include <UltraSonicSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

