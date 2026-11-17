#include <Arduino.h>

int LEDs[4] = {21, 19, 17, 16};

void setup() {
  pinMode(26, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(32, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(LEDs[i], OUTPUT);
  }

  Serial.begin(115200);
}

void loop() {
  byte value = 0;

  value |= (!digitalRead(32)) << 0;
  value |= (!digitalRead(33)) << 1;
  value |= (!digitalRead(25)) << 2;
  value |= (!digitalRead(26)) << 3;

  // Part 4 - 2's complement
  value ^= 0b1111;
  Serial.print("Inverted: ");
  Serial.println(value, BIN);
  value += 1;
  // End for 2's complement

  for (int i = 0; i < 4; i++) {
    digitalWrite(LEDs[i], (value >> i) & 0x01);
  }

  Serial.print("Value: ");
  Serial.println(value);
  delay(500);
}