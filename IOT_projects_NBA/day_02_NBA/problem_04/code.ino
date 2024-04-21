// ThinkSpank, BlinkApp_Combine


#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#define BLYNK_TEMPLATE_ID "TMPL3RjvNafLN"
#define BLYNK_TEMPLATE_NAME "LED ON off"
#define BLYNK_AUTH_TOKEN "fgH-zEGfalFWBg1xv40WFy-C6yt3x3pH"
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

const char* ssid = "saikat1234";
const char* pass = "12345678";
WiFiClient client;
unsigned long myChannelNumber =  2513607;
const char * myWriteAPIKey = "UVHL9DHI4GDFK5TI";
const char * myReadAPIKey = "KF1PCS1V119Q8JLA";
int led_1;
int led2 = D1;
int ldr = A0;
int val =0;

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


void setup() {
  Serial.begin(115200);
  
 pinMode(led2,OUTPUT);
  WiFi.begin(ssid, pass);
  ThingSpeak.begin(client);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(D3,OUTPUT);

}
void loop() {
  val = analogRead(ldr);
  Serial.println(val);
 ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey);
 led_1 = ThingSpeak.readIntField(myChannelNumber, 1, myReadAPIKey);
Serial.println(led_1);
if(led_1<200)
{
digitalWrite(led2,HIGH);
}
else
{
digitalWrite(led2,LOW);
}
  delay(1000);
  Blynk.run();

}