#include <CayenneMQTTSerial.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <DHT.h>

char username[] = "c9973ca0-fa46-11ed-8485-5b7d3ef089d0";
char password[] = "4d3642c83f6372afaf62548a636b8c2e1c81509b";
char clientID[] = "8f172510-fa80-11ed-9ab8-d511caccfe8c";

#define DHTPIN 2
#define DHTTYPE DHT11

#define TEMPERATURA 1
#define HUMEDAD 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID);
  dht.begin();
}

void loop() {
  Cayenne.loop();
}

CAYENNE_OUT(TEMPERATURA) {
  Cayenne.virtualWrite(TEMPERATURA, dht.readTemperature(), "temp", "c");
}

CAYENNE_OUT(HUMEDAD) {
  Cayenne.virtualWrite(HUMEDAD, dht.readHumidity(), "rel_hum", "p");
}