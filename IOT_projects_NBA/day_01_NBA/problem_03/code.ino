#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <DHT.h>
WiFiClient client;
const char* ssid = "realme"; //Your Network SSID
const char* password = "12345678"; //Your Network Password

unsigned long myChannelNumber = 2515813;
const char * myWriteAPIKey = "UOM16RL9ZEA00NN7";
const char * myReadAPIKey = "2FTB2O4BPB6BTJ7E";
#define DHTPIN D2          //pin where the dht11 is connected
DHT dht(DHTPIN, DHT11);
int temp;
int hum;
int light;
int led1 = D6;
int led2 = D7;
int led3 = D8;
int ldr = A0;
int val =0;
void setup(){
Serial.begin(115200);
WiFi.begin(ssid, password);
dht.begin();
ThingSpeak.begin(client);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}
void loop(){

float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.println(h);
Serial.println(t);
val = analogRead(ldr);
Serial.println(val);
ThingSpeak.setField(1, h);
ThingSpeak.setField(2, t);
ThingSpeak.setField(3, val);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
hum = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
temp = ThingSpeak.readIntField(myChannelNumber, 2, myReadAPIKey);
light = ThingSpeak.readIntField(myChannelNumber, 3, myReadAPIKey);
Serial.println(hum);
if(hum<100)
{
digitalWrite(led1,HIGH);
}
else
{
digitalWrite(led1,LOW);
}
Serial.println(temp);
if(temp<40)
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
Serial.println(light);
if(light<200)
{
digitalWrite(led3,HIGH);
}
else
{
digitalWrite(led3,LOW);
}
delay(15000);
}