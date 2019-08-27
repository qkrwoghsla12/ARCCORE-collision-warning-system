/**
 * Generated RTE
 *
 * @req SWS_Rte_01169
 */

/** === HEADER ====================================================================================
 */

/** @req SWS_Rte_01279 */
#include <Rte.h>

/** @req SWS_Rte_01257 */
#include <Os.h>

#if ((OS_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION))
#error Os version mismatch
#endif

/** @req SWS_Rte_03794 */
#include <Com.h>

#if ((COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || (COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION))
#error Com version mismatch
#endif

/** @req SWS_Rte_01326 */
#include <Rte_Hook.h>

#include <Rte_Internal.h>

#include <Ioc.h>

#include "Gpt.h"
#include "Rte_CanTranslateSWC.h"

#define Timer_Freq 40000000
#define TIMER_TICK2NS( _x )     ((_x) * 25)
//#define TASK3
/** === Os Macros =================================================================================
 */

#define END_OF_TASK(taskName) SYS_CALL_TerminateTask()

#define ARC_STRINGIFY(value)  ARC_STRINGIFY2(value)
#define ARC_STRINGIFY2(value) #value

#if defined(ARC_INJECTED_HEADER_RTE_C)
#define  THE_INCLUDE ARC_STRINGIFY(ARC_INJECTED_HEADER_RTE_C)
#include THE_INCLUDE
#undef   THE_INCLUDE
#endif

#if !defined(RTE_EXTENDED_TASK_LOOP_CONDITION)
#define RTE_EXTENDED_TASK_LOOP_CONDITION 1
#endif

extern EcuM_ModeMachinesType EcuM_ModeMachines; /*lint -e9003 RTE Requirement */

/** === Generated API =============================================================================
 */

/** === Runnables =================================================================================
 */
extern void Rte_FrontLedSWC_LEDActuator(void);
extern void Rte_RearLedSWC_LEDActuator(void);
extern void Rte_cantranslateSWC_CanTranslate(void);
extern void Rte_collisiondetectionSWC_CollisionDetection(void);
extern void Rte_modeManagerInitSWC_Init(void);
extern void Rte_ultrasonicSWC_UltraSonic(void);

/** === Tasks =====================================================================================
 */

/*lint -e522 lint does not understand that low level calls to void operator are needed */
/*lint -e160 warning only viable if in c++ */
/*lint -e950 asm command needs to be used*/
/*lint -e9008 The comma operator is acceptable even with loss of readability */

void OsCollisionDetectionTask(void) { /** @req SWS_Rte_02251 */
    EventMaskType Event;
#ifdef TASK1
    Gpt_ValueType current, prev;
    Gpt_StartTimer(GPT_CHANNEL_PIT_2, 0xffffffff);
#endif
    do {
        SYS_CALL_WaitEvent (EVENT_MASK_OsCollisionDetectionEvent); /*lint !e534 RTE Requirement */
        SYS_CALL_GetEvent(TASK_ID_OsCollisionDetectionTask, &Event); /*lint !e534 RTE Requirement */

        if ((Event & EVENT_MASK_OsCollisionDetectionEvent) != 0) {
            SYS_CALL_ClearEvent(EVENT_MASK_OsCollisionDetectionEvent);/*lint !e534 RTE Requirement */
            Rte_collisiondetectionSWC_CollisionDetection();
        }
#ifdef TASK1
        prev = current;
    	current = Gpt_GetTimeElapsed(GPT_CHANNEL_PIT_2);
    	Rte_IWrite_CanTranslate_CanTxPort_message((IntImpl)(TIMER_TICK2NS(current-prev)));
#endif
    } while (RTE_EXTENDED_TASK_LOOP_CONDITION != 0); /*lint !e506 RTE Requirement */
}

void OsLEDTask(void) { /** @req SWS_Rte_02251 */
    EventMaskType Event;
#ifdef TASK2
	Gpt_ValueType current, prev;
	Gpt_StartTimer(GPT_CHANNEL_PIT_2, 0xffffffff);
#endif

    do {
        SYS_CALL_WaitEvent (EVENT_MASK_OsLEDEvent); /*lint !e534 RTE Requirement */
        SYS_CALL_GetEvent(TASK_ID_OsLEDTask, &Event); /*lint !e534 RTE Requirement */

        if ((Event & EVENT_MASK_OsLEDEvent) != 0) {
            SYS_CALL_ClearEvent(EVENT_MASK_OsLEDEvent);/*lint !e534 RTE Requirement */
            Rte_FrontLedSWC_LEDActuator();
        }
        if ((Event & EVENT_MASK_OsLEDEvent) != 0) {
            SYS_CALL_ClearEvent(EVENT_MASK_OsLEDEvent);/*lint !e534 RTE Requirement */
            Rte_RearLedSWC_LEDActuator();
        }
#ifdef TASK2
        prev = current;
    	current = Gpt_GetTimeElapsed(GPT_CHANNEL_PIT_2);
    	Rte_IWrite_CanTranslate_CanTxPort_message((IntImpl)(TIMER_TICK2NS(current-prev)));
#endif
    } while (RTE_EXTENDED_TASK_LOOP_CONDITION != 0); /*lint !e506 RTE Requirement */
}

void OsSonarTask(void) { /** @req SWS_Rte_02251 */
	EventMaskType Event;
#ifdef TASK3
    Gpt_ValueType current, prev;
    Gpt_StartTimer(GPT_CHANNEL_PIT_2, 0xffffffff);
#endif

    do {
        SYS_CALL_WaitEvent (EVENT_MASK_OsSonarEvent); /*lint !e534 RTE Requirement */
        SYS_CALL_GetEvent(TASK_ID_OsSonarTask, &Event); /*lint !e534 RTE Requirement */

        if ((Event & (EVENT_MASK_OsSonarEvent)) != 0) {
            /* Check that a switch has been requested (nextMode is not a transition) */
            if (EcuM_ModeMachines.ecuM.currentMode_currentMode.nextMode != RTE_TRANSITION_EcuM_ecuM_currentMode_currentMode) {
                EcuM_ModeMachines.ecuM.currentMode_currentMode.previousMode = EcuM_ModeMachines.ecuM.currentMode_currentMode.currentMode;
                EcuM_ModeMachines.ecuM.currentMode_currentMode.currentMode = RTE_TRANSITION_EcuM_ecuM_currentMode_currentMode; /* Indicate ongoing transition */

                /* Activate runnables ON-EXIT */
                if (EcuM_ModeMachines.ecuM.currentMode_currentMode.previousMode == RTE_MODE_EcuM_ecuM_currentMode_currentMode_STARTUP) {
                    Rte_modeManagerInitSWC_Init();
                }
            }
        }
        if ((Event & EVENT_MASK_OsSonarEvent) != 0) {
            SYS_CALL_ClearEvent(EVENT_MASK_OsSonarEvent);/*lint !e534 RTE Requirement */
            Rte_cantranslateSWC_CanTranslate();
        }
        if ((Event & EVENT_MASK_OsSonarEvent) != 0) {
            SYS_CALL_ClearEvent(EVENT_MASK_OsSonarEvent);/*lint !e534 RTE Requirement */
            Rte_ultrasonicSWC_UltraSonic();
        }
        if ((Event & (EVENT_MASK_OsSonarEvent)) != 0) {
            /* Check that a transition is ongoing */
            if (EcuM_ModeMachines.ecuM.currentMode_currentMode.currentMode == RTE_TRANSITION_EcuM_ecuM_currentMode_currentMode) {

                EcuM_ModeMachines.ecuM.currentMode_currentMode.currentMode = EcuM_ModeMachines.ecuM.currentMode_currentMode.nextMode;
                EcuM_ModeMachines.ecuM.currentMode_currentMode.nextMode = RTE_TRANSITION_EcuM_ecuM_currentMode_currentMode; /* Indicate that no transition is requested (nextMode can be a transition) */
                EcuM_ModeMachines.ecuM.currentMode_currentMode.transitionCompleted = TRUE;
            }
        }
        /* Clear event set by ModeSwitch */
        if ((Event & EVENT_MASK_OsSonarEvent) != 0) {
            SYS_CALL_ClearEvent(EVENT_MASK_OsSonarEvent); /*lint !e534 RTE Requirement */
        }

        EcuM_ModeMachines.ecuM.currentMode_currentMode.transitionCompleted = FALSE;
#ifdef TASK3
        prev = current;
    	current = Gpt_GetTimeElapsed(GPT_CHANNEL_PIT_2);
    	Rte_IWrite_CanTranslate_CanTxPort_message((IntImpl)(TIMER_TICK2NS(current-prev)));
#endif

    } while (RTE_EXTENDED_TASK_LOOP_CONDITION != 0); /*lint !e506 RTE Requirement */
}

