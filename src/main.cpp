#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3zJqEPaQn"
#define BLYNK_TEMPLATE_NAME "Smart Crop Stress Detection System"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <BH1750.h>

// -------- Blynk Credentials --------
char auth[] = "bjHp52Nzeu7cZF__YwZCiupTKG7_9cdG";
char ssid[] = "G16 ES";
char pass[] = "nointernet";

// -------- Pin Definitions --------
#define DHTPIN 4
#define DHTTYPE DHT11
#define SOIL_PIN 34
#define RELAY_PIN 23

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;

BlynkTimer timer;

// -------- Threshold --------
int soilThreshold = 2000;

// -------- Stress Calculation --------
float calculateStress(int soil, float temp, float light) {
  float soilStress = map(soil, 1500, 3500, 0, 40);
  float tempStress = map(temp, 20, 40, 0, 30);
  float lightStress = map(light, 0, 1000, 0, 30);

  float stressIndex = soilStress + tempStress + lightStress;

  if (stressIndex > 100) stressIndex = 100;
  if (stressIndex < 0) stressIndex = 0;

  return stressIndex;
}

// -------- Sensor Function --------
void readSensors() {
  Serial.println("------ Sensor Data ------");

  int soilValue = analogRead(SOIL_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  delay(2000);
  float lux = 0;
  if (lightMeter.measurementReady()) {
    lux = lightMeter.readLightLevel();
  } else {
    Serial.println("BH1750 not ready");
  }

  float stressIndex = calculateStress(soilValue, temperature, lux);
  // -------- STATUS MESSAGE --------
  String statusMsg;

  if (stressIndex < 30) {
    statusMsg = "Optimal Conditions";
  }
  else if (stressIndex < 60) {
    statusMsg = "Moderate Stress";
  }
  else {
    statusMsg = "High Stress";
  }

  // Print values
  Serial.print("Soil Moisture: "); Serial.println(soilValue);
  Serial.print("Temperature: "); Serial.println(temperature);
  Serial.print("Humidity: "); Serial.println(humidity);
  Serial.print("Light: "); Serial.println(lux);
  Serial.print("Crop Stress Index: "); Serial.println(stressIndex);
  Serial.print("Status:");Serial.println(statusMsg);
  // Pump control
  if (soilValue > soilThreshold) {
    digitalWrite(RELAY_PIN, LOW);  // ON
    Serial.println("Pump ON - Soil Dry");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // OFF
    Serial.println("Pump OFF - Soil Wet");
  }

  // Send to Blynk
  Blynk.virtualWrite(V0, soilValue);
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, lux);
  Blynk.virtualWrite(V4, stressIndex);
  Blynk.virtualWrite(V5, statusMsg);
  Serial.println("--------------------------\n");
}

// -------- Setup --------
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("System Started");

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF initially
  
  dht.begin();
  
  Wire.begin(21, 22); // SDA, SCL
  lightMeter.begin();

  Blynk.begin("bjHp52Nzeu7cZF__YwZCiupTKG7_9cdG", "G16 ES", "nointernet");

  timer.setInterval(4000L, readSensors);
}

// -------- Loop --------
void loop() {
  Blynk.run();
  timer.run();
}