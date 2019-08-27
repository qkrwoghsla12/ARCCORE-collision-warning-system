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

#include "Rte_CanTranslateSWC.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ cantranslateSWC -----------------------------------------------------------------------
 */
void Rte_cantranslateSWC_CanTranslate(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define CanTranslateSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_cantranslateSWC_CanTranslate_CanRxPort_message; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define CanTranslateSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define CanTranslateSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_cantranslateSWC_CanTranslate_CanTxPort_message; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define CanTranslateSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define CanTranslateSWC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_cantranslateSWC_CanTranslate_SonarRecv_distance; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*/
#define CanTranslateSWC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define CanTranslateSWC_START_SEC_CONST_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_CanTranslateSWC CanTranslateSWC_cantranslateSWC = {
    .CanTranslate_SonarRecv_distance = &ImplDE_cantranslateSWC_CanTranslate_SonarRecv_distance,
    .CanTranslate_CanRxPort_message = &ImplDE_cantranslateSWC_CanTranslate_CanRxPort_message,
    .CanTranslate_CanTxPort_message = &ImplDE_cantranslateSWC_CanTranslate_CanTxPort_message
};
#define CanTranslateSWC_STOP_SEC_CONST_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define CanTranslateSWC_START_SEC_CONST_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_CanTranslateSWC = &CanTranslateSWC_cantranslateSWC;

#define CanTranslateSWC_STOP_SEC_CONST_UNSPECIFIED
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ cantranslateSWC -----------------------------------------------------------------------
 */

#define CanTranslateSWC_START_SEC_CODE
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_cantranslateSWC_CanTranslate(void) {

    /* PRE */
    Rte_Read_CanTranslateSWC_cantranslateSWC_SonarRecv_distance(&ImplDE_cantranslateSWC_CanTranslate_SonarRecv_distance.value); /*lint !e534 AUTOSAR API */

    Rte_Read_CanTranslateSWC_cantranslateSWC_CanRxPort_message(&ImplDE_cantranslateSWC_CanTranslate_CanRxPort_message.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    canTranslate();

    /* POST */

    Rte_Write_CanTranslateSWC_cantranslateSWC_CanTxPort_message(ImplDE_cantranslateSWC_CanTranslate_CanTxPort_message.value); /*lint !e534 AUTOSAR API */

}
#define CanTranslateSWC_STOP_SEC_CODE
#include <CanTranslateSWC_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

