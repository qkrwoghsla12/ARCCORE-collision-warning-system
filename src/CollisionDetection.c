#include "Rte_CollisionDetectionSWC.h"
#define COLLISION_DISTANCE 30
#define RED 10
#define YELLOW 20
#define LOW 0
#define HIGH 1

void collisionDetection(void){
	IntImpl SonarDistance;

	SonarDistance = Rte_IRead_CollisionDetection_SonarRecv_distance();
	if(SonarDistance <= RED){
		Rte_IWrite_CollisionDetection_RearStatus_Status(HIGH);
		Rte_IWrite_CollisionDetection_FrontStatus_Status(LOW);
	}
	else if(SonarDistance <= YELLOW){
		Rte_IWrite_CollisionDetection_RearStatus_Status(LOW);
		Rte_IWrite_CollisionDetection_FrontStatus_Status(HIGH);
	}
	else{
		Rte_IWrite_CollisionDetection_FrontStatus_Status(LOW);
		Rte_IWrite_CollisionDetection_RearStatus_Status(LOW);
	}
}
