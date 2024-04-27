#include <WiFi.h>;
#include <ThingSpeak.h>;
const char* ssid = "M2"; //Your Network SSID
const char* password = "12345678"; //Your Network Password
int val1;
int val2;
int MQ135 = 32;
int MQ3 = 34;
WiFiClient client;
unsigned long myChannelNumber =   2516307; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "NVV0JWBTKADBP6QL"; //Your Write API Key

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
  WiFi.mode(WIFI_STA);
}
void loop() {
  val1 = analogRead(MQ135);
  val2 = analogRead(MQ3);
  Serial.println(val1);
  Serial.println(val2);
ThingSpeak.setField(1, val1);
ThingSpeak.setField(2, val2);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
delay(10000);
}