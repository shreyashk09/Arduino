
byte data = 0;                //Variable for storing received data
int LED = 4;
int ROOMLIGHT = 3;
int ACpin = 2;
int LED2 = 5;
int Buzzer = 13;
float temp;
int ldr;
int autom1 = 1;
int autom2 = 1;
int sensors_on = 1;

void setup() 
{
  Serial.begin(9600);         
  pinMode(ACpin, OUTPUT);
  pinMode(ROOMLIGHT, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}
void loop()
{
 // digitalWrite(Buzzer, LOW);
  if(Serial.available() > 0)  // Send data only when you receive data:
  {
    data = Serial.read();      
    Serial.print(data);       
    Serial.print("\n");       
    if(int(data) == 49) 
       sensors_on = 1;
    else if(int(data) == 50)       
       sensors_on = 0;
       
    else if(int(data) == 51)       
      autom1 = 1;
    else if(int(data) == 52)       
      autom1 = 0;

      
    else if(int(data) == 53)       
      autom2 = 1;
    else if(int(data) == 54)       
      autom2 = 0;

      
    else if(int(data) == 55)    
      {digitalWrite(LED, HIGH);
      digitalWrite(LED2, HIGH);
       digitalWrite(Buzzer, HIGH);
      }
    else if(int(data) == 56)       
      {digitalWrite(LED, LOW);
      digitalWrite(LED2, LOW);
       digitalWrite(Buzzer, LOW);
      }

    
  }

  if(sensors_on){
    temperature();
    light();
    if(temp>50){
      digitalWrite(Buzzer, HIGH);
      }
     else{
      digitalWrite(Buzzer, LOW);
      if(autom1){
        if(temp>40)
            digitalWrite(ACpin, HIGH);
         else
            digitalWrite(ACpin, LOW);
        }
      }
    if(ldr>800){
      digitalWrite(Buzzer, HIGH);
      }
     else{
      digitalWrite(Buzzer, LOW);
      if(autom2){
      if(ldr>150)
            digitalWrite(ROOMLIGHT, HIGH);
         else
            digitalWrite(ROOMLIGHT, LOW);
        }
        }
    }
                           
}

void temperature(){
  temp = analogRead(A0);
  temp = temp * 0.4882815;
  Serial.print("tmepreture: ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
 }
void light(){
   ldr = analogRead(A1);
   Serial.print("LDR: ");
  Serial.println(ldr);  
  }
