

#define BLYNK_TEMPLATE_ID "TMPL4AY1zVVV"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_AUTH_TOKEN "ivfIXpefq-rA9JGXGTQ7Tb1vcMwEi6_m"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "OPPO F19 Pro";
char pass[] = "12345678";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D3, HIGH);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(D3, LOW);
     Serial.println("LED OFF");
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(D3,OUTPUT);
  
}

void loop()
{
  Blynk.run();
}