/*
  Created by: Osamah
  Created on: APR 2025
  Servo Control with Ultrasonic Sensor
*/

#include <Servo.h>

Servo servoNumber1;

const int trigPin = 3;
const int echoPin = 2;

int servostop = 1000;
int angleone = 0;
int angletwo = 90;
int anglethree = 180;

float duration, distance;

void setup() {
  // Setup pins for servo and ultrasonic sensor
  servoNumber1.attach(4);
  servoNumber1.write(0);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Ultrasonic sensor operation
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");  // Adding " cm" to the Serial output


  // Check if distance is less than 5 cm
  if (distance < 40) {
    servoNumber1.write(angletwo);  // Move to 90 degrees
    delay(servostop);
  }

  if (distance < 40) {
    servoNumber1.write(angleone);  // Move to 0 degrees
    delay(servostop);
  }

  if (distance < 40) {
    servoNumber1.write(anglethree);  // Move to 180 degrees
    delay(servostop);
  }

  if (distance < 40) {
    servoNumber1.write(angleone);  // Move to 0 degrees
    delay(servostop);  
  }
  
  delay(100); // Small delay to avoid excessive readings
}