//////////////////
//Angel Martinez
//Control servo
/////////////////
#include <TM1637Display.h>
#include <Servo.h>
Servo servo1;
int conta;
const int abrirbarrera=A2;
const int cerrarbarrera=A1;
#define CLK 8
#define DIO 7
#define TEST_DELAY   2000
TM1637Display display(CLK, DIO);
void setup() { 
servo1.attach(9);
pinMode (abrirbarrera,INPUT);
pinMode (cerrarbarrera,INPUT);
digitalWrite(A1,HIGH);
digitalWrite(A2,HIGH);
}
void loop() {
  display.setBrightness(0x0f);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
if (digitalRead(cerrarbarrera)==1&&digitalRead(abrirbarrera)==0){;
 servo1.write(0);
conta=0;
}
if (digitalRead(abrirbarrera)==1&&digitalRead(cerrarbarrera)==0){;
servo1.write(90);
conta= 90;
}
 display.showNumberDec(conta, false, 2,2);
 delay(100);
  display.setSegments(data);
}
