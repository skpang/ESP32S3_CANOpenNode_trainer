/*
CANOpenNode Demo
trevorH 2.19.23

This code demonstrates the use of CANOpenNode on the ESP32 Wrover Processor.  It utilizes the Arduino core for ESP32
provided by espressif: https://github.com/espressif/arduino-esp32

The code utilizes PDO messages to display data with intervals of 1.5seconds and heart beat messages with an interval
of 1 second.  And SDO messages are read repeatedly with large intervals of 100ms and also as quickly as possible for several times
during that read session.

The node IDs for the devices that are tested are 9 and 10 but additional nodes could easily be added with different IDs.  Node
9 will request SDO data from Node 10.

The system utilizes freeRTOS to generate the tasks for implementation of CANOpenNode (as described in their documentation) as well
as a CAN_ctrl_task for setup of the TWAI CAN hardware within the ESP32 and processing messages two and from CANOpenNode.  This
function utilizes to queues for CAN messages that should be received and those that should be transmitted.

Basic error recovery has been implemented for CANtimeouts, errors and disconnection but this should be updated for better robustness

*/
#include "CANOpen_skp.h"

void setup()
{
	  pinMode(LED_R,OUTPUT);
    pinMode(LED_G,OUTPUT);
    pinMode(LED_B,OUTPUT);
    pinMode(LED_CO_RUN,OUTPUT);
    pinMode(LED_CO_ERR,OUTPUT);
    pinMode(LED3,OUTPUT);
    pinMode(LED4,OUTPUT);
    pinMode(SW1,INPUT_PULLUP);
    pinMode(SW2,INPUT_PULLUP);

    digitalWrite(LED_B, OFF);
    digitalWrite(LED_G, OFF);
    digitalWrite(LED_R, OFF);
    digitalWrite(LED_CO_RUN, LOW);
    digitalWrite(LED_CO_ERR, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    
	  Serial.begin(115200);
	  digitalWrite(LED_R, ON);
    delay(200); 
    digitalWrite(LED_R, OFF);
    
    digitalWrite(LED_G, ON);
    delay(200); 
    digitalWrite(LED_G, OFF);
    
    digitalWrite(LED_B, ON);
    delay(200); 
    digitalWrite(LED_B, OFF);

    digitalWrite(LED_CO_RUN, HIGH);
    delay(200); 
    digitalWrite(LED_CO_RUN, LOW);

    digitalWrite(LED_CO_ERR, HIGH);
    delay(200); 
    digitalWrite(LED_CO_ERR, LOW);

    digitalWrite(LED3, HIGH);
    delay(200); 
    digitalWrite(LED3, LOW);

    digitalWrite(LED4, HIGH);
    delay(200); 
    digitalWrite(LED4, LOW);

		Serial.println("##########################################################################################");
		Serial.println("ESP32S3 CANopenNode trainer skpang.co.uk 10/2025");
	  
    CO_setup();
	
}

//Seperate thread started by FreeRTOS.  This loop() accesses Node9 data by writing and reading SDO messages
void loop()
{
	CO_loop();

}
