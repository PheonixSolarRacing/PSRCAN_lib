#include "FlexCAN_Library\FlexCAN.h"

uint32_t baud;
FlexCAN CANBus;
CAN_message_t txmsg, rxmsg;

void setBaud(uint32_t baud);
int sendMessage(const CAN_message_t &);


int sendMessage(const CAN_message_t &msg){
  return write(msg);
}

void setBaud(uint32_t baud){
  
}


void setup() {
  // put your setup code here, to run once:
  CANBus(baud);
  CANBus.begin();
  delay(500); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
