// This example uses an Arduino/Genuino Zero together with
// a WiFi101 Shield or a MKR1000 to connect to shiftr.io.
//
// IMPORTANT: This example uses the new WiFi101 library.
//
// You can check on your device after a successful
// connection here: https://shiftr.io/try.
//
// by Gilberto Conti
// https://github.com/256dpi/arduino-mqtt

#include <SPI.h>
#include <WiFi101.h>
#include <MQTTClient.h>

#define SOUND_PIN A0

char *ssid = "YOUR_SSID";
char *pass = "YOUR_PASS";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin("io.adafruit.com", net);

  connect();
}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("YOU_AIO_USER", "YOUR_AIO_USER", "YOUR_AIO_KEY")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

//  client.subscribe("YOUR_AIO_USER/f/noiseometer");
}

void loop() {
  client.loop();

  if(!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if(millis() - lastMillis > 5000) {
    lastMillis = millis();
    int rawValue = analogRead(SOUND_PIN);
    client.publish("YOUR_AIO_USER/f/noiseometer", String(rawValue));
  }
}

void messageReceived(String topic, String payload, char * bytes, unsigned int length) {
  Serial.print("incoming: ");
  Serial.print(topic);
  Serial.print(" - ");
  Serial.print(payload);
  Serial.println();
}