#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("LM35 Test");
  delay(1000);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage*100;
  // print out the value you read:
  Serial.println("Voltage : ");
  Serial.println(voltage);
  Serial.println("Temperature : ");
  Serial.println(temperature);

  lcd.setCursor(0,0);
  lcd.print("T :");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");
  delay(500);
}
