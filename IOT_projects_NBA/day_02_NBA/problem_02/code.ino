//Touch Sensor ,by  Blink App 

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLQkEF9z57"
#define BLYNK_DEVICE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "qd2sCWkopxka551lN69BAp0vQgmkq-xT"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "AriTra";
char pass[] = "htcf9295";


/* HC-SR501 Motion Detector */
#define ledPin D4 
#define pirPin D1 // Input for HC-S501
int pirValue; // Place to store read PIR Value

void setup()
{
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  //digitalWrite(ledPin, LOW);
}



/***************************************************
 * Get PIR data
 **************************************************/
void getPirValue(void)
{
  pirValue = digitalRead(pirPin);
  if (pirValue) 
  { 
    Serial.println("==> Motion detected");
    //Blynk.notify("T==> Motion detected");  
    digitalWrite(ledPin, HIGH); 
    //Blynk.virtualWrite(V0,pirValue);
    Blynk.virtualWrite(V1,pirValue);
  }
  
    else {
    digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
    //digitalWrite(buzzer, LOW); // turn LED ON
    Serial.println("Hey I not got you!!!");
   // Blynk.virtualWrite(V0,pirValue);
    Blynk.virtualWrite(V1,pirValue);
   
  }
}
void loop()
{
  getPirValue();
  Blynk.run();
}