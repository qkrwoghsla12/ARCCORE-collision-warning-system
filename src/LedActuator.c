#include "Rte_LEDActuatorSWC.h"
#define LOW 0
#define HIGH 1

void ledActuator(Rte_Instance self){
	LedStatusImpl LedStatus;
	LedStatus = Rte_IRead_LEDActuator_Status_Status(self);

	Rte_Call_DigitalLED_Write(self, LedStatus);
}
