/////////////////////////
//Angel Martinez
//Display Zumbador LCDI2C
/////////////////////////
#include <TM1637Display.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#define CLK 8
#define DIO 7
#define TEST_DELAY   2000
int conta=0;
TM1637Display display(CLK, DIO);

void setup()
{
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(6,OUTPUT);
digitalWrite(A0,HIGH);
digitalWrite(A1,HIGH);  
lcd.init();
lcd.backlight();
lcd.setCursor(3,0);

}

void loop()
{


  display.setBrightness(0x0f);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
  if (digitalRead (A0)==0){
   conta++;
  display.showNumberDec(conta, false, 2,2);
 delay(100);
   digitalWrite(6,HIGH);
   delay(200);
   digitalWrite(6,LOW);
    lcd.setCursor(3,0);
  lcd.print("Su turno");
  delay(1000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Espere");
  delay(500);
  }
    if (digitalRead (A1)==0){
   conta--;
   if (conta<=0){
    conta=0;
    }
   digitalWrite(6,HIGH);
   delay(200);
   digitalWrite(6,LOW);

    }
  display.showNumberDec(conta, false, 2,2);
 delay(100);

  display.setSegments(data);
  
}
 
  
