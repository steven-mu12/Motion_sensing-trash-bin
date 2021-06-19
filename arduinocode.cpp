
#include <Servo.h>
Servo servo;

const int trigPin = 11;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(12);
  servo.write(90);
  Serial.begin(9600);
}

void loop() {

  // sending out the distancing ranging program
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  calculateDistance();

  // operate the servo lid opening mechanism depending on the distance

  if(distance <= 15){
    Serial.print("OPEN");
    Serial.print("\n");
    
    servo.write(135);
    delay(400);
    servo.write(90);
    delay(4000);
    servo.write(45);
    delay(315);
    servo.write(0);
  }
  
  else if (distance > 15){
    Serial.print("CLOSED");
    Serial.print("\n"); 
    servo.write(90);  
  }
}

int calculateDistance(){
  distance = duration * 0.034 / 2;
  return distance;
}
