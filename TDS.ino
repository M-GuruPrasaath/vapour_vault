#define TDS_PIN 34  // Connect the AOUT of TDS sensor to GPIO 34

void setup() {
  Serial.begin(115200);
  pinMode(TDS_PIN, INPUT);
}

void loop() {
  // Read the analog value from the TDS sensor
  int sensorValue = analogRead(TDS_PIN);
  
  // Map the sensor value (0 to 4095) to TDS range
  // This is an example. You might need to calibrate it based on your TDS sensor
  float voltage = sensorValue * (3.3 / 4095.0); // ESP32 ADC resolution is 12-bit (0-4095)
  
  // Print the voltage and the corresponding TDS value
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, TDS Value: ");
  Serial.println(sensorValue); // You can implement a formula to convert voltage to TDS
  
  delay(1000);  // Wait for 1 second
}
