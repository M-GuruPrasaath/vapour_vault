#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define the one-wire bus pin and DS18B20 sensor setup
#define ONE_WIRE_BUS 15 // GPIO15 for DS18B20 data pin
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Define the LCD address (0x27 is common, might be different for your LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16x2 LCD, I2C address 0x27

void setup() {
  // Start the serial communication
  Serial.begin(115200);

  // Start the I2C communication for LCD
  Wire.begin(21, 22); // SDA, SCL pins for ESP32
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  
  // Initialize the DS18B20 sensor
  sensors.begin();
  
  delay(2000);
  lcd.clear();
}

void loop() {
  sensors.requestTemperatures();  // Request temperature from the DS18B20 sensor
  float tempC = sensors.getTempCByIndex(0); // Get temperature in Celsius
  
  // Display the temperature on the LCD
  lcd.setCursor(0, 0);              // Set the cursor to the first line
  lcd.print("Temp: ");              // Print the label
  lcd.setCursor(6, 0);              // Move the cursor to print the temperature value
  lcd.print(tempC);                 // Print the temperature value
  lcd.print(" C");                  // Print the unit

  delay(2000);  // Wait for 2 seconds before updating again
}
