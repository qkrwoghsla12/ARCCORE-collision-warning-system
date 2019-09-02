# ARCCORE-collision-warning-system
## SWC Implementation
- **UltraSonicSWC** : After converting the measured data using the ultrasonic sensor into distance data in cm, this performs the operation of transmitting to the CanTranslateSWC and CollisionDetectionSWC. There are SonarTrig and SonarEcho client ports to request Digital I/O function through the ioHwAb, and the SonarSend Sender Port exists to transmit converted data to other SWCs.
  
- **CanTranslateSWC** : To transmit the data received from the UltraSonicSWC to the CAN bus using the CAN communication stack, one must connect the CanTxPort Sender Port of the CanTranslateSWC to the CanTxPortOut Sender Port of the collision detection root software composition. There is a SonarRecv Receiver Port for receiving the ultrasonic sensor data, and there exists a CanTxPort Sender Port for transmitting data to the COM module of the BSW through the CanTxPortOut port of the collision detection root software composition.
  
- **CollisionDetectionSWC** : Using the data received from the UltraSonicSWC, this determines the LED to be controlled according to the risk of collision with the obstacle and sends it to the LEDActuatorSWC. If the value of data is more than 200 cm, it does not generate a warning. If it is 100 ~ 200 cm, the yellow LED lights up. If it is less than 100 cm, the red LED lights up. The SonarRecv Receiver Port exists to receive the ultrasonic sensor data, and the YLEDStatus and RLEDStatus Sender Ports exist for the control of the yellow and red LEDs, respectively. 
  
- **LEDActuatorSWC** : This controls the LED according to the LED control signal received from the CollisionDetectionSWC. There is a Status Receiver Port to receive the LED control status and there is a DigitalLED Client Port to request the Digital I/O function through ioHwAb. 
  
- **ModeManagerSWC** : This transmits the ECU control signals to the ecuM and bswM, and lets the BSW perform Ecu, Gpt (general purpose timer), and communication initialization functions. There is a ComMControl Sender Port, which sends messages to the bswM for turning on/off the PDUs used for CAN communication; a Mode Receiver Port, for obtaining the status information that the ECU is currently operating from the ecuM; and a RunControl Client Port, for requesting a change in operation of the ECU. 
  
  
## BSW Module Configuration
| module | method |
|--|--|
| Dio | Provides a service to read/write for the Digital I/O channels, ports, and channel groups. In order to control the LED and ultrasonic sensors using the GPIO provided by the MCU, the DioChannel was configured. |
| Port | Provides a service to initialize the PORT structure of the MCU. In order to initialize the ports of the MCU with the LEDs and ultrasonic sensors, and to connect the CAN transceiver, the direction and mode of use of the ports were configured. |
| IoHwAb | Provides a service to enable the SWC to access the MCAL I/O drivers. In order to control the LED and ultrasonic sensors in the SWC, the signals of the RTE and the DioChannel of the Dio module were mapped. |
| Gpt | Provides a service to initialize and control the internal general purpose timer of the MCU. In order to measure the return time of the ultrasonic sensor, the General Purpose Timer Physical Channel was configured and the channel mode was configured in the continuous mode, so that the timer started automatically. | 
|EcuM|This is a module that manages the common part of the ECU. This was configured to enable ECU status management and ECU operation modes.|
|BswM|This provides mode arbitration and mode control, and interacts with other BSW modules and SWCs. In order to process the I-PDU group used in the communication stack, Mode Arbitration and Mode Control were configured.|
|Mcu|Provides services for MCU related functions such as MCU initialization. We configured the clock of the MCU and the mode used in the ECU.|
|EcuC|This is a virtual module that is used when there is information to be shared among several BSW modules. PDU objects used in the communication stack are used by several BSW modules that make up the communication stack. PDU objects used for CAN communication were configured.|
|OS|This is a real-time operating system based on OSEK OS, which is an event triggered operating system and provides a platform for SWC execution. In order to schedule the runnable of the SWC, the task was configured and the task priority was specified. The Alarm and Event were configured for the period setting of the task, which performs periodic execution. Alarms trigger the specified event every set period. The configured tasks were the OsStartupTask, OsBswServiceTask, OsCollisionDetectionTask, OsLEDTask, and OsSonarTask.|
|Can|Performs hardware dependent functions such as controlling the CAN controller, and provides a hardware-independent API to the upper layer CanIf module. The CAN Hardware Object receive (Rx), transmit (Tx), CAN Baudrate, and Segment were configured.|
|CanIf|Provides the interface between the upper layer PduR and the Can module (the lower module) and initializes the Can module. The PDU, including the frame ID and the frame length and transmitted/received using the Can communication, is constructed.|
|PduR|Routes the PDU sent from the Com module to the Communication Interface Module on the BSW ECU abstraction layer. The PDU received from the Com module is configured to route to the CanIf Module.|
|Com|Converses the AUTOSAR signal received from the RTE to I-PDU used in the BSW layer and performs communication transmission control. The number of bits and byte order of the signal received from the RTE were configured and the I-PDU transmission control period was configured.|
|CanSM|Manages the status and control flow of the CAN communication network. We configured the bus off the recovery time for the recovery of the CAN network.|
