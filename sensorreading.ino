#include "DHT.h"
#define DHTPIN 2  
#define DHTTYPE DHT22  

String waterStat1 = (" ");
String waterStat2 = (" ");

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  int waterOne = analogRead(A0);
  Serial.print("Water1: ");
  Serial.print(waterOne);
  Serial.print(" ");
  int waterTwo = analogRead(A1);
  Serial.print("Water2: ");
  Serial.print(waterTwo);
  Serial.print(" ");
  Serial.println();
  if (waterOne < 208) {
    waterStat1 = ("Water Soon! ");
  }
  if (waterOne >= 208) {
    waterStat1 = ("Good on water for now! ");
  }
  if (waterOne == 0){
    waterStat1 = ("Dried Out! ");
  }
   if (waterTwo < 285) {
    waterStat2 = ("Water Soon! ");
  }
  if (waterTwo >= 285) {
    waterStat2 = ("Good on water for now! ");
  }
  if (waterTwo == 0) {
    waterStat2 = ("Dried Out! ");
  }
  Serial.print(waterStat1);
  Serial.print(waterStat2);
  Serial.println();

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F "));
  Serial.println();

}
