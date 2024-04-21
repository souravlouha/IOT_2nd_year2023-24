// Firebase related problem

#include "FirebaseESP8266.h"  
#include <ESP8266WiFi.h>
#include <DHT.h>    
#define FIREBASE_HOST "https://subhajit-7af42-default-rtdb.asia-southeast1.firebasedatabase.app//" 
#define FIREBASE_AUTH "AIzaSyA6gMCNCc82nnRy5mfD51nr9ViPYc6LVWs"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "12345678"

#define DHTPIN D2    
   

#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);

//Define FirebaseESP8266 data object
FirebaseData firebaseData;



void setup()
{

  Serial.begin(9600);

  dht.begin();
  
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void sensorUpdate(){
  
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();
  

  
  if (isnan(h) || isnan(t) ) {
    Serial.println(("Failed to read from DHT sensor!"));
    return;
  }

  
  Serial.println(h);
  
  Serial.println(t);

  if (Firebase.pushFloat(firebaseData, "/FirebaseIOT/temperature", t))
  {
    Serial.println("PASSED");

  }
  else
  {
    Serial.println("FAILED");

  }

  if (Firebase.pushFloat(firebaseData, "/FirebaseIOT/humidity", h))
  {
    Serial.println("PASSED");
    
  }
  else
  {
    Serial.println("FAILED");
    
  }
}
void loop() {
  sensorUpdate();
  delay(100);
}

_________________________________________________________________________________________________________________________________________________________











#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "https://subhajit-7af42-default-rtdb.asia-southeast1.firebasedatabase.app//" 
#define FIREBASE_AUTH "AIzaSyA6gMCNCc82nnRy5mfD51nr9ViPYc6LVWs"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "12345678"
int led = D5;     // Connect LED to D5

//FirebaseData firebaseData;
FirebaseData ledData;

//FirebaseJson json;


void setup()
{

  Serial.begin(9600);

    pinMode(led,OUTPUT);
  
  
  
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);


}

void loop() {
    
  if (Firebase.getString(ledData, "/FirebaseIOT/led")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "1") {
    digitalWrite(led, HIGH);
    }
  else if (ledData.stringData() == "0"){
    digitalWrite(led, LOW);
    }
  }
  delay(1000);
}
__________________________________________________________________________________________________________________________________________________







#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
#include <DHT.h>    // Install DHT11 Library and Adafruit Unified Sensor Library


#define FIREBASE_HOST "https://subhajit-7af42-default-rtdb.asia-southeast1.firebasedatabase.app//" //Without http:// or https:// schemes
#define FIREBASE_AUTH "AIzaSyA6gMCNCc82nnRy5mfD51nr9ViPYc6LVWs"
#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "12345678"

#define DHTPIN D4    // Connect Data pin of DHT to D2
int led = D5;     // Connect LED to D5

#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);

//Define FirebaseESP8266 data object
FirebaseData firebaseData;
FirebaseData ledData;

//FirebaseJson json;


void setup()
{

  Serial.begin(9600);

  dht.begin();
  pinMode(led,OUTPUT);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void sensorUpdate(){
  
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();
  

  
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  
  Serial.println(h);
  
  Serial.println(t);

  if (Firebase.pushFloat(firebaseData, "/FirebaseIOT/temperature", t))
  {
    Serial.println("PASSED");

  }
  else
  {
    Serial.println("FAILED");

  }

  if (Firebase.pushFloat(firebaseData, "/FirebaseIOT/humidity", h))
  {
    Serial.println("PASSED");
    
  }
  else
  {
    Serial.println("FAILED");
    
  }
}
void loop() {
  sensorUpdate();
  
  if (Firebase.getString(ledData, "/FirebaseIOT/led")){
    Serial.println(ledData.stringData());
    if (ledData.stringData() == "1") {
    digitalWrite(led, HIGH);
    }
  else if (ledData.stringData() == "0"){
    digitalWrite(led, LOW);
    }
  }
  delay(100);
}

_______________________________________________________________________________________________________________________________________________________

