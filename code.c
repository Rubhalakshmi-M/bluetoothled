#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX (Connect HC-05 TX → D10, RX ← D11 via voltage divider)

int led1 = 5;
int led2 = 6;

void setup() {
  BT.begin(9600); // Start Bluetooth communication
  Serial.begin(9600); // For debugging (optional)

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (BT.available()) {
    char value = BT.read(); // Read from Bluetooth
    Serial.println(value);  // Debug print (optional)

    switch (value) {
      case 'O':
        digitalWrite(led1, HIGH);
        break;
      case 'F':
        digitalWrite(led1, LOW);
        break;
      case 'A':
        digitalWrite(led2, HIGH);
        break;
      case 'B':
        digitalWrite(led2, LOW);
        break;
    }
  }
}
