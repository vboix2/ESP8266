// Importem la llibreria per gestionar la wifi
#include <ESP8266WiFi.h>    // WiFiManager by tablatronix


void setup() {
  // Inicialitzem el monitor sèrie
  Serial.begin(9600);

  // Connectem el microcontrolador a la wifi
  WiFi.mode(WIFI_STA);                     // Configura la placa en mode estació
  WiFi.begin("SSID", "password");          // Guarda les claus de la wifi a la memòria de la placa
  
  Serial.print("Connectant a la xarxa");  // Missatge de connexió al monitor
  
  while (WiFi.status() != WL_CONNECTED) {  // Esperem a que es connecti
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connectada");      // Missatge de connexió correcta
  Serial.print("Adreça IP: ");
  Serial.println(WiFi.localIP());         // Mostrem la IP de la placa a la xarxa

}

void loop() {
  
}
