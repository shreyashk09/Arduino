#define BLYNK_PRINT DebugSerial
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX
#define BLYNK_PRINT SwSerial

int LDR = A1;
    
#include <BlynkSimpleStream.h>

#include <SPI.h>

char auth[] = "1e259730d1984638b6b849e5de66efcc";
byte data = 0;               
int Lightpin = 2;
int Fanpin = 3;
int TVpin = 4;
int ACpin = 5;
int Buzzer = 12;
float temp;
int ldr;

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  SwSerial.print("V1 Slider value is: ");
  SwSerial.println(pinValue);
}

void setup()
{
  // Debug console
  SwSerial.begin(9600);
  DebugSerial.begin(9600);
  //Serial.begin(9600);
  Blynk.begin(Serial, auth);
  pinMode(LDR, INPUT);
  pinMode(Lightpin, OUTPUT);
  pinMode(Fanpin, OUTPUT);
  pinMode(TVpin, OUTPUT);
  pinMode(ACpin, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Lightpin, HIGH);
  digitalWrite(Fanpin, HIGH);
  digitalWrite(ACpin, HIGH);
  digitalWrite(TVpin, HIGH);
}

void loop()
{
  //Blynk.run();
  //digitalWrite(Buzzer, HIGH);
  digitalWrite(Lightpin, HIGH);
  digitalWrite(Fanpin, HIGH);
  digitalWrite(ACpin, HIGH);
  digitalWrite(TVpin, HIGH);
}
