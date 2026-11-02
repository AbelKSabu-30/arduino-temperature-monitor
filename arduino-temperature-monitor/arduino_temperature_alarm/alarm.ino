
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define LED_PIN 8
#define BUZZER_PIN 9
#define TEMP_THRESHOLD 100.0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();

  Serial.println("Temperature Monitoring and Alarm System");
  Serial.println("Alarm threshold: 26 C");
}

void loop() {
  delay(2000);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Sensor reading failed!");

    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    Serial.println("WARNING: HIGH TEMPERATURE!");
    Serial.println("LED: ON | BUZZER: ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Temperature normal.");
    Serial.println("LED: OFF | BUZZER: OFF");
  }

  Serial.println("-------------------------");
}
