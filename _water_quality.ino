#include <Arduino.h>

int redled = 6;
int greenled = 7;

void setup(void) {
  Serial.begin(9600); // Initialize Serial communication
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
}

void loop(void) {
  int sensorValue = analogRead(A0);
  // print out the value you read:
  int turbidity = map(sensorValue, 0, 700, 100, 0);

  Serial.print("TURBIDITY: ");
  Serial.print(turbidity);
  Serial.println("%");

  if (turbidity < 35) {
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
  } else {
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, HIGH);
  }

  delay(1000);
}