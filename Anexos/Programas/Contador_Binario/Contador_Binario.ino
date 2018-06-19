////////////////////
//Angel Martinez
//Contador Binario
///////////////////

int conta=0;
int tabla [16]={0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60};
void setup() {
pinMode(A0,INPUT);
pinMode(A1,INPUT);
digitalWrite(A0,HIGH);
digitalWrite(A1,HIGH);
DDRD=1111111;
}

void loop() {
if (digitalRead(A0)==0){
while(digitalRead(A0)==0){}
conta++;
delay(200);
if (conta==16){
conta=15;
}
PORTD=tabla[conta];
}
if (digitalRead(A1)==0){
while(digitalRead(A1)==0){}
conta--;
delay(200);
if (conta<0){
conta=0;
}
PORTD=tabla[conta];
}
}
