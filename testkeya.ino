//Reads all traffic on CAN0 and forwards it to CAN1 (and in the reverse direction) but modifies some frames first.
// Required libraries
#include "variant.h"
#include <due_can.h>

//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

void setup()
{

  Serial.begin(115200);
  
  // Initialize CAN0 and CAN1, Set the proper baud rates here
  Can0.begin(CAN_BPS_250K);
  Can1.begin(CAN_BPS_250K);
  
  Can0.watchFor();  
}

void sendData(short prm)
{
  CAN_FRAME outgoing;
  outgoing.id = 0x601;
  outgoing.extended = false;
  outgoing.priority = 4; //0-15 lower is higher priority
  
  //outgoing.data.s0 = 0xFEED;
  //  outgoing.data.byte[2] = 0xDD;
  //outgoing.data.byte[3] = 0x55;
 // outgoing.data.high = 0xDEADBEEF;
 outgoing.data.bytes[0]=0x23;
 outgoing.data.bytes[1]=0x00;
 outgoing.data.bytes[2]=0x20;
 outgoing.data.bytes[3]=0x01;
 outgoing.data.bytes[4]=prm&0xff;
 outgoing.data.bytes[5]=(prm>>8)&0xff;
 outgoing.data.bytes[6]=0x00;
 outgoing.data.bytes[7]=0x00;
 Can0.sendFrame(outgoing);
}
int pr=0;
int dr;
void loop(){
  CAN_FRAME incoming;
  sendData(-100); 
  delay(10);  
}


