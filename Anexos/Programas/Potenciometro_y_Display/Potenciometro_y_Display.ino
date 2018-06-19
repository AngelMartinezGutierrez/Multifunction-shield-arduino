//////////////////////////
// Angel Marinez
// Potenciometro y display
//////////////////////////
#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 8
#define DIO 7
#define TEST_DELAY   2000
TM1637Display display(CLK, DIO);

int potenciometro;
int voltios;
void setup() {
Serial.begin(9600);
}
void loop() {
potenciometro=analogRead(A3);
voltios=map(potenciometro,0,1023,0,5);
display.setBrightness(0x0f);
uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
display.setSegments(data);
display.showNumberDec(voltios, false, 2,2);
delay(100);

display.setSegments(data);
}
