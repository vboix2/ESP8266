// Importem les llibreries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Claus de la wifi
const char* ssid     = "SSID";
const char* password = "password";

ESP8266WebServer server(80);  // Creem l'objecte servidor al port 80


void setup() {
  Serial.begin(9600);
  IniciWifi();            // Connectem la placa a la xarxa
  IniciServidor();        // Iniciem el servidor
}

void loop() {
  server.handleClient();  // Rebem les peticions del client i enviem la informació solicitada
}

void IniciWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connectant a la xarxa ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connectada");
  Serial.print("Adreça IP: ");
  Serial.println(WiFi.localIP());
}

void IniciServidor() {
  // Resposta al directori arrel
  server.on("/", handleRoot);

  // Resposta al directori 'pagina'
  server.on("/pagina", []() {
    server.send(200, "text/plain", "Aquí tenim una nova pàgina");
  });

  // Resposta a pàgines no trobades
  server.onNotFound(handleNotFound);

  // Iniciem el servidor
  server.begin();
  Serial.println("HTTP server started");
}

void handleRoot() {
  server.send(200, "text/plain", "Hola món!");
}

void handleNotFound() {
  server.send(404, "text/plain", "Pàgina no trobada");
}
