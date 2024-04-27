#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "https://iot333-8e11b-default-rtdb.asia-southeast1.firebasedatabase.app//" 
#define FIREBASE_AUTH "AIzaSyD6q62Qu0IHn4l46Mirsh8CiJ468fSDVPI"
#define WIFI_SSID "M2"
#define WIFI_PASSWORD "12345678"
int led = D5;     // Connect LED to D5

//FirebaseData firebaseData;
FirebaseData IoT333;

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
    
  if (Firebase.getString(IoT333, "/DHT/LED")){
    Serial.println(IoT333.stringData());
    if (IoT333.stringData() == "1") {
    digitalWrite(led, HIGH);
    }
  else if (IoT333.stringData() == "0"){
    digitalWrite(led, LOW);
    }
  }
  delay(1000);
}