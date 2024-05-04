#define LM35Pin A0
int LM35Read;
float temperature;

void setup() {
  Serial.begin(9600);
}

void loop() {
// Saving reading from A9 to LM35Read variable  
  LM35Read= analogRead(LM35Pin); 
// Convert the reading to temp. in Celcius
  temperature = LM35Read * (5.0 / 1024.0) *100; 
// Print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C  ");
// Print the temperature in Fahrenheit
  Serial.print((temperature * 9.0 / 5.0) + 32.0);
  Serial.println("F");
  delay(1000); 
}   