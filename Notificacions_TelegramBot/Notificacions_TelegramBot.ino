#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

String token = "BOT_TOKEN";
String chat_id = "CHAT_ID";

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(token, client);

int minuts = 0;
unsigned long previous_millis = 0;


void setup() {
  Serial.begin(9600);
  configTime(0, 0, "pool.ntp.org");
  client.setTrustAnchors(&cert);
  
  connectToWiFi();
  bot.sendMessage(chat_id, "S'ha iniciat el bot", "");
}

void loop() {
  bot.sendMessage(chat_id, "Han passat " + String(minuts) + " minuts", "");
  waitTime();
  minuts++;
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

void waitTime() {
  unsigned long current_millis = millis();
  while (current_millis < (previous_millis + 60000)) {
    delay(10000);
    current_millis = millis();
    Serial.print(".");
  }
  previous_millis = current_millis;
  Serial.println();
}
