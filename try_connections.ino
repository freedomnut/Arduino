#include <SPI.h>
#include <WiFi101.h>

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int TryOtherWifi = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Checking 2WIRE connectivity...");
  WiFi.begin("2WIRE518", "4135157230");
  delay(5000);

  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("2WIRE connection unsuccessful.");
    WiFi.disconnect();
    TryOtherWifi = 1;
  }
  else {
    Serial.println("2WIRE connection successful!");
  }

  if (TryOtherWifi == 1) {
    Serial.println("Trying MakerHQ connectivity...");
    WiFi.begin("MakerHQ", "sacramentomaker916");
    delay(5000);

    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("MakerHQ connection unsuccessful.");
      WiFi.disconnect();
    }
    else {
      Serial.println("MakerHQ connection sucessful!");
    }
  }
}

void loop() {

}
