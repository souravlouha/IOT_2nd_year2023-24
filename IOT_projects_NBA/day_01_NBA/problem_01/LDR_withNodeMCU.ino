#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ThingSpeak.h>

const char* ssid = "Galaxy A12 FB6B"; //Your Network SSID

const char* password = "87654321"; //Your Network Password

int val;

int tempPin = A0;

WiFiClient client;

unsigned long myChannelNumber = 2515813; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "UOM16RL9ZEA00NN7"; //Your Write API Key



void setup() {

Serial.begin(115200);
WiFi.begin(ssid, password);
ThingSpeak.begin(client);

}

void loop() {
  val = analogRead(tempPin);


Serial.println(val);
//delay(1000);

ThingSpeak.setField(1, val);

ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

delay(15000);
}