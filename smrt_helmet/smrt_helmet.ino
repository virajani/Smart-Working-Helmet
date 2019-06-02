
#include <dht.h>
dht melani;
//temp sensor
int Buzzer1=9;
const int ledpin=12;

//gas sensor
const int MQ3=0;
const int Buzzer=8;
const int LED=12;
int value;

//Light sensor
const int ldr_pin = 6;
const int led_pin = 13;



void setup() {
  Serial.begin(9600);
  pinMode(MQ3, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(Buzzer,LOW);
  digitalWrite(LED,LOW);

  //ldr
  pinMode(ldr_pin,INPUT);
  pinMode(led_pin,OUTPUT);

  //temp sensor
  pinMode(ledpin,OUTPUT);
  pinMode(Buzzer1,OUTPUT);
  delay(500);  

}

void loop()
{
  value= analogRead(MQ3);
  Serial.println(value);
  
  if(value>500)
  {
    digitalWrite(Buzzer,HIGH);
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(Buzzer,LOW);
    digitalWrite(LED,LOW);
  }

 // delay (510);

  //ldr

  if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
   }
   else{
      digitalWrite( led_pin , LOW);
   }
   
   Serial.println( digitalRead( ldr_pin ));
   delay(100);


   //temp
  int val=melani.read11(7);

  Serial.print("Temperature=");
  Serial.println(melani.temperature);
  Serial.print("\t Humidity=");
  Serial.println(melani.humidity);
   
 if(melani.temperature>28){
  digitalWrite(ledpin,HIGH);
  digitalWrite(Buzzer1,HIGH);
  tone(9,200,2000);
  }
  delay(500);
   
}
