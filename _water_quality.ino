#include <Arduino.h>

int leftled = 6;
int rightled = 7;

void setup(void) {
  Serial.begin(9600); 
  pinMode(leftled, OUTPUT);
  pinMode(rightled, OUTPUT);
}

void loop(void) {
  int sensorValue = analogRead(A0);
  int turbidity = map(sensorValue, 0, 700, 100, 0);

  Serial.print("TURBIDITY: ");
  Serial.print(turbidity);
  Serial.println("%");

  if (turbidity < 35) {
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, LOW);
  } else {
    digitalWrite(leftled, HIGH);
    digitalWrite(rightled, HIGH);
  }

  delay(1000);
}
