#include <Arduino.h>

#define TRIG_PIN 12
#define ECHO_PIN 11



void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.println("Ultrasonic Ready");

}


long readUltrasonic(){
  digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

return pulseIn(ECHO_PIN, HIGH);
}

void loop() {
long microseconds = readUltrasonic();
float distance = (microseconds * 0.0343) / 2.0;

Serial.print("DATA: ");
Serial.println(distance);

delay(100);

}

int myFunction(int x, int y) {
  return x + y;
}