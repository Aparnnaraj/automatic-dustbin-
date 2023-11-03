#include <Servo.h>
Servo servo;

int trig= 5;
int echo= 6;
int servoPin= 7;
int led= 10;

long duration, distance, average;
long aver[3];

void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trig, OUTPUT);  
    pinMode(echo, INPUT);  
    servo.write(0);         
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trig, LOW);
delayMicroseconds(5);
digitalWrite(trig, HIGH);
delayMicroseconds(15);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
duration = pulseIn(echo, HIGH);
distance = (duration/2) / 29.1;    
}

void loop() { 
  for (int i=0;i<=2;i++) {   
    measure();               
   aver[i]=distance;            
    delay(10);              
  }
 distance=(aver[0]+aver[1]+aver[2])/3;    

if ( distance<50 ) {

 servo.attach(servoPin);
  delay(1);
 servo.write(0);  
 delay(3000);       
 servo.write(150);    
 delay(1000);
 servo.detach();      
}
Serial.print(distance);
}
