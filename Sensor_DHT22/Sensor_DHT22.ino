// Importem la llibreria del sensor
#include <DHT.h>  // DHT sensor library by Adafruit

// Creem l'objecte sensor, de tipus DHT22 i connectat al pin 4
DHT dht(D4, DHT22);

// Constant que guarda el nombre de mesures que farem per cicle
const int N_MEASURES = 10;

void setup() {
  // Inicialitzem el sensor i el monitor
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // Variables que acumularan les lectures del sensor
  float sum_temp = 0.0f;
  float sum_hum = 0.0f;
  int successes = 0;

  // Fem 10 mesures durant 10 segons
  for (int i=0; i<N_MEASURES; i++){
    delay(500);
    int hum = dht.readHumidity();
    delay(500);
    int temp = dht.readTemperature();

    // Comptem les mesures correctes
    if (!isnan(temp) && !isnan(hum)){
      sum_temp = sum_temp + temp;
      sum_hum = sum_hum + hum;
      successes++;
    }
  }

  // Calculem la mitjana de les mesures
  float temperatura = sum_temp / successes;
  float humitat = sum_hum / successes;

  // Mostrem els resultats per pantalla
  Serial.print("Temperatura: " + String(temperatura) + "ºC\t");
  Serial.println("Humitat: " + String(humitat) + "%");
}
