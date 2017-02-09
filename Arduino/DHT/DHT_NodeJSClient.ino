#include "DHT.h"

#define DHTPIN A0
#define DHTTYPE DHT11   // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

unsigned int nTimer = 6000; // milliseconds

void setup() {
  Serial.begin(9600);
  dht.begin();

  delay(1000);
}

int initialTime = millis();

void loop() {
  int newTime = millis();
  if ((newTime-initialTime) >= nTimer) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(t) && !isnan(h)) {
      Serial.print(h);
      Serial.print(',');
      Serial.println(t);
    }
    initialTime = newTime;
  }
}
