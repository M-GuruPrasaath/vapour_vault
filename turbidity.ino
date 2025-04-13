#define TURBIDITY_PIN 34  // ADC pin where AO is connected

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Turbidity Sensor Initialized...");
}

void loop() {
  int sensorValue = analogRead(TURBIDITY_PIN);  // Read analog value (0–4095)

  // Convert analog value to voltage (ESP32 ADC: 0–4095 for 0–3.3V)
  float voltage = sensorValue * (3.3 / 4095.0);

  // Simple linear approximation from sensor datasheet
  float ntu = 0;
  
  if (voltage < 2.5) {
    ntu = (2.5 - voltage) * 300;  // Example calibration formula
  } else {
    ntu = 0;  // Clean water
  }

  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Turbidity: ");
  Serial.print(ntu, 2);
  Serial.println(" NTU");

  delay(1000);  // 1-second delay
}
