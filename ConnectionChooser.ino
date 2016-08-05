#include <SPI.h>
#include <WiFi101.h>
int status = WL_IDLE_STATUS;     // the Wifi radio's status

void setup() {
  Serial.begin(9600);
  Serial.println("Trying home wifi...");
  GetConnected();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void GetConnected() {
  TryHomeWifi();
  if (status != WL_CONNECTED) {
    WiFi.disconnect();
    Serial.println("Home wifi could not be obtained. Trying MakerHQ wifi.");
    TryMakerWifi();
    if (status != WL_CONNECTED) {
      Serial.println("Weren't able to connect to Maker wifi, either. :(");
      WiFi.disconnect();
    }
    else {
      Serial.println("Connected to MakerHQ wifi. :)");
    }
  }
  else {
    Serial.println("Connected to home wifi. :)");
  }
}

void TryHomeWifi() {
  TryWifi("2WIRE518", "000000000");
}
void TryMakerWifi() {
  TryWifi("MakerHQ", "sacramentomaker916");
}

void TryWifi(const char *ssidIn, const char *passIn) {
  int Counter = 0;
  const char *sSSID = ssidIn;
  const char *sPass = passIn;
  while (Counter <= 5 && status != WL_CONNECTED) {
    status = WiFi.begin(sSSID, sPass);
    Counter++;
    delay(1000);
  }
  
}

