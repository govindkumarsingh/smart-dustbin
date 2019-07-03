#include <Servo.h>   //servo library
Servo servo;     
int trigPin1 = 2;    
int echoPin1 = 3;


int servoPin = 8;
long duration, dist,dist1;   
long aver1[3];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin1, OUTPUT);  
    pinMode(echoPin1, INPUT);
    servo.write(180);         //close cap on power on
    delay(100);
    servo.detach(); 
} 

long measure(int trigPin,int echoPin) {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
return dist;
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
   dist1= measure(trigPin1,echoPin1);               
   aver1[i]=dist1; 
   delay(10);              //delay between measurements
  }
 dist1=(aver1[0]+aver1[1]+aver1[2])/3;   //average distance
Serial.println(dist1);
if ( dist1<20) {
 servo.attach(servoPin);
  delay(1);
 servo.write(180);  
 delay(3000);       
 servo.write(50);    
 delay(1000);
 servo.detach();      
}

}
