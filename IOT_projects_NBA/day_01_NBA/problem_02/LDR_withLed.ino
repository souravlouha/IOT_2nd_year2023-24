#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
const char* ssid = "realme";
const char* password = "12345678";
WiFiClient client;
unsigned long myChannelNumber = 2515813;
const char * myWriteAPIKey = "UOM16RL9ZEA00NN7";
const char * myReadAPIKey = "2FTB2O4BPB6BTJ7E";
int led_1;
int led2 = D1;
int ldr = A0;
int val =0;

void setup() {
  Serial.begin(115200);
  
 pinMode(led2,OUTPUT);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}
void loop() {
  val = analogRead(ldr);
  Serial.println(val);
 ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
 led_1 = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
Serial.println(led_1);
if(led_1<300)
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
  delay(15000);
}