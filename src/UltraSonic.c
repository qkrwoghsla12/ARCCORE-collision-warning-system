#include "Rte_UltraSonicSWC.h"
#include "Gpt.h"
#include "timer_stm.c"


#define Timer_Freq 40000000
#define TIMER_TICK2NS( _x )     (((_x)*1000) / (Timer_Freq/1000000uL))

void UltraSonic(void){
	DigitalLevel level;
	SignalQuality quality;
	IntImpl SonarDistance;
	Gpt_ValueType current, prev;

	Rte_Call_SonarTrig_Write(0);
	Timer_uDelay(2);
	Rte_Call_SonarTrig_Write(1);
	Timer_uDelay(5);
	Rte_Call_SonarTrig_Write(0);

	do{
		Rte_Call_SonarEcho_Read(&level, &quality);
	}while(level == 0);
	Gpt_StartTimer(GPT_CHANNEL_PIT_1, 1000000);
	prev = Gpt_GetTimeElapsed(GPT_CHANNEL_PIT_1);
	do{
		Rte_Call_SonarEcho_Read(&level, &quality);
	}while(level == 1);
	current = Gpt_GetTimeElapsed(GPT_CHANNEL_PIT_1);
	Gpt_StopTimer(GPT_CHANNEL_PIT_1);

	SonarDistance = (IntImpl)(TIMER_TICK2US(current-prev)/29.1/2);
	Rte_IWrite_UltraSonic_SonarSend_distance(SonarDistance);
}
