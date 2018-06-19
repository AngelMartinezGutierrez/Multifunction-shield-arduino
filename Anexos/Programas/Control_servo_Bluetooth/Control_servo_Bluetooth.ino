///////////////////////
//Angel Martinez
//Control servo Bluetooth
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial BT1(0,1);
byte pos;
Servo servo1;
void setup(){

  Serial.begin(9600);
  BT1.begin(9600);
  servo1.attach(9);
}
void loop(){
if(BT1.available()){
  pos=BT1.read();
  Serial.print(pos);
  if(pos>9 && pos<171) servo1.write(pos);  

}
}
