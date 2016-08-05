#include <SPI.h>
#include <WiFi101.h>

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int TryOtherWifi = 0;
int Connected = 0;

void setup() {
  Serial.begin(9600);
  //Serial.println("Checking 2WIRE connectivity...");
  //WiFi.begin("2WIRE518", "0000000000");
  //delay(5000);
  //if(WiFi.status() != WL_CONNECTED) {
  //  Serial.println("2WIRE connection unsuccessful.");
  //  WiFi.disconnect();
  //  TryOtherWifi = 1;
  //}
  //else {
  //  Serial.println("2WIRE connection successful!");
  //}
  //if (TryOtherWifi == 1) {
  //  Serial.println("Trying MakerHQ connectivity...");
  //  WiFi.begin("MakerHQ", "sacramentomaker916");
  //  delay(5000);
  //  if (WiFi.status() != WL_CONNECTED) {
  //    Serial.println("MakerHQ connection unsuccessful.");
  //    WiFi.disconnect();
  //  }
  //  else {
  //    Serial.println("MakerHQ connection sucessful!");
  //  }
  //}

  Connected = ConnectWiFi();
  if (Connected == 1) {
    Serial.println ("WiFi connection made.  We're ready to run!");
  }
  else {
    Serial.println ("WiFi connection couldn't be made, which is double plus ungood.");
  }
}

int ConnectWiFi() {
  int result = 0;
  TryOtherWifi = TryWiFi("2WIRE518", "4135157230");
  if (TryOtherWifi == 1) {
    TryOtherWifi = TryWiFi("MakerHQ", "sacramentomaker916");
  };
  if (TryOtherWifi == 0) {
    Serial.print ("WiFi connection made.");
    result = 0;
  }
  else {
    Serial.print ("WiFi connection could not be made.");
    result = 1;
  }  
  return result;
}
int TryWiFi(char ssid, char pass) {
  int result = 0;
  Serial.println("Trying " + ssid + " wifi connectivity...");
  WiFi.begin(ssid, pass);
  delay(3000);
  
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(ssid + " connection unsuccessful. :(");
    WiFi.disconnect();
    result = 0;
  }
  else {
    Serial.println(ssid + " wifi connection successful! :)");
    result = 1;
  }
  return result;
}

void loop() {}
