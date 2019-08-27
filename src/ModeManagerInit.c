#include "Rte_ModeManagerSWC.h"
#include "Gpt.h"

void EcuModeManagerInit(void){
	Timer_Init();
	Gpt_Init(GptChannelConfigSet);

	(void)Rte_Call_RunControl_RequestRUN();
	Rte_IWrite_Init_ComMControl_requestedMode(COMM_FULL_COMMUNICATION);
}
