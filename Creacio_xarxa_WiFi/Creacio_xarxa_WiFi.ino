// Importem la llibreria per gestionar la wifi
#include <ESP8266WiFi.h>

// Configuració de la WiFi generada
const char *ssid = "SSID";
const char *password = "password";

void setup() {
  // Inicialitzem el monitor sèrie
  Serial.begin(9600);
  delay(10);

  // Configura la placa en mode access point
  WiFi.mode(WIFI_AP);
  while(!WiFi.softAP(ssid, password)){
   Serial.println(".");
    delay(100);
  }
  
  Serial.print("Iniciant AP ");
  Serial.println(ssid);
  Serial.print("IP address:\t");
  Serial.println(WiFi.softAPIP());
  
}

void loop() { }
