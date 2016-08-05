#include <SPI.h>
#include <WiFi101.h>

char ssid[] = "2WIRE518";     //  your network SSID (name)
char pass[] = "0000000000";  // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
  int WifiAttempt;

void setup() {
  Serial.begin(9600);
  PerformChecks();
  GetConnectedToAWifi();
  
  WifiAttempt = AttemptWifiConnection(ssid, pass);
}


void PerformChecks() {
  // Check for the presence of the shield
  Serial.print("WiFi101 shield: ");
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("NOT PRESENT");
    return; // don't continue
  }
  Serial.println("DETECTED");

  // Print firmware version on the shield
  String fv = WiFi.firmwareVersion();
  Serial.print("Firmware version installed: ");
  Serial.println(fv);

  // Check if the required version is installed
  Serial.println();
  if (fv == WIFI_FIRMWARE_REQUIRED) {
    Serial.println("Check result: PASSED");
  } else {
    Serial.println("Check result: NOT PASSED");
    Serial.println(" - The firmware version on the shield do not match the");
    Serial.println("   version required by the library, you may experience");
    Serial.println("   issues or failures.");
  }
  end;  
}

int AttemptWifiConnection(char ssid, char pass) {
  int result;
  int loopCounter = 0;

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: " + ssid);
    status = WiFi.begin(ssid, pass);
  }


  return result;
}

void loop() {
  // put your main code here, to run repeatedly:

}
