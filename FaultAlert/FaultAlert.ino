#define BLYNK_TEMPLATE_ID "TMPL3Sxw7J-_L"
#define BLYNK_TEMPLATE_NAME "smart street light system"

#include <BlynkSimpleEsp32.h>
#include <WiFi.h>

char auth[] = "qngOrz01-vJmHjGWPqJLv75zrE9yBk0-";
char ssid[] = "vivo V27";
char pass[] = "00000000";

const int ldrPin0 = 35;
const int ldrPin1 = 4;
const int ldrPin2 = 2;
const int ldrPin3 = 25;
const int ldrPin4 = 26;

const int ledPin1 = 15;
const int ledPin2 = 12;
const int ledPin3 = 14;
const int ledPin4 = 13;


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
  pinMode(ldrPin4, INPUT);

  pinMode(ldrPin0, INPUT);
}

void loop() {
  Blynk.run();

  int ldrValue = digitalRead(ldrPin0);
  int ldrPinValue1 = digitalRead(ldrPin1);
  int ldrPinValue2 = digitalRead(ldrPin2);
  int ldrPinValue3 = digitalRead(ldrPin3);
  int ldrPinValue4 = digitalRead(ldrPin4);
  
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue == HIGH) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    Serial.println("Dark: LEDs ON");
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("Bright: LEDs OFF");
    Blynk.logEvent("LEDs turned off!"); // Log event when LEDs turn off
  }

  if (ldrPinValue1 == HIGH) {
    digitalWrite(ldrPin1, HIGH);
    Serial.println("Fault Alert: Light 1");
    Blynk.logEvent("Fault Alert: Light 1 turned off!"); // Log event for light 1
  }

  if (ldrPinValue2 == HIGH) {
    digitalWrite(ldrPin2, HIGH);
    Serial.println("Fault Alert: Light 2");
      // Log event for light 2
  }

  if (ldrPinValue3 == HIGH) {
    digitalWrite(ldrPin3, HIGH);
    Serial.println("Fault Alert: Light 3");
    Blynk.logEvent("Fault Alert: Light 3 turned on!"); // Log event for light 3
  }

  if (ldrPinValue4 == HIGH) {
    digitalWrite(ldrPin4, HIGH);
    Serial.println("Fault Alert: Light 4");
    Blynk.logEvent("Fault Alert: Light 4 turned off!"); // Log event for light 4
  }

  delay(500);
}
