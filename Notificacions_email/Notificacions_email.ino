#include <ESP8266WiFi.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";
const char* host = "maker.ifttt.com";

const String event_name = "IFTTT_EVENT_NAME";
const String apiKey = "IFTTT_API_KEY";
const String url = "/trigger/" + event_name + "/with/key/" + apiKey;

WiFiClient client;

int minuts = 0;     // Comptador del temps transcorregut

void setup() {
  Serial.begin(9600);
  connectToWiFi();
}

void loop() {
  // Envia un missatge per correu electrònic cada minut
  
  int longitud = String(minuts).length() + 7;      // Longitud de les dades a enviar
    
  if (client.connect(host, 80)){                  // Connexió al servidor
    Serial.println("Enviant dades...");

    // Enviem dades amb el mètode POST
    client.print("POST " + url + " HTTP/1.1\r\n");
    client.print("Host: " + String(host) + "\r\n");
    client.print("Content-Type: application/x-www-form-urlencoded\r\n");
    client.print("Content-Length: " + String(longitud) + "\r\n\r\n");
    client.print("value1=" + String(minuts) + "\r\n");
    
    Serial.println("Dades enviades");
  }
  waitTime();
  minuts++;        // Incrementem el valor
}

void connectToWiFi(){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void waitTime(){
  Serial.print("Esperant");
  for (int i=0; i<6; i++){
    delay(10000);
    Serial.print(".");
  }
  Serial.println(".");
}
