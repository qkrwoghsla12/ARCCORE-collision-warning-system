#include "Rte_CanTranslateSWC.h"

void canTranslate(void){
	IntImpl distance=0;
	distance = Rte_IRead_CanTranslate_SonarRecv_distance();
	Rte_IWrite_CanTranslate_CanTxPort_message(distance);

	//IntImpl prev,recv=0;
	//recv = Rte_IRead_CanTranslate_CanRxPort_message();
	//Rte_IWrite_CanTranslate_CanTxPort_message(0x00);
	//if(prev != recv){
		//Rte_IWrite_CanTranslate_CanTxPort_message(recv);
	//	prev = recv;
	//}
}
