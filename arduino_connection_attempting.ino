#include <SPI.h>
#include <WiFi101.h>
#include <MQTTClient.h>


const char *ssid = "2WIRE518";
const char *pass = "0000000000";

#define SOUND_PIN A0

#define SENSOR_INTERVAL 50   // in milliseconds
#define SAMPLE_INTERVAL 2    // in seconds
#define REPORT_INTERVAL 2   // in seconds



#define NUM_SENSOR_VALUES (1000/SENSOR_INTERVAL*SAMPLE_INTERVAL)
#define NUM_REPORT_VALUES (REPORT_INTERVAL/SAMPLE_INTERVAL)

int sensor_values[NUM_SENSOR_VALUES];
int report_values[NUM_REPORT_VALUES];

unsigned long last_report;
unsigned long last_sample;
unsigned long last_sensor;

unsigned long now;

int cur_sensor = 0;
int cur_sample = 0;
int sensor_idx = 0;
int report_idx = 0;

WiFiClient net;
MQTTClient client;

void setup() {
  
}

int ConnectWiFi(char WiFiName, char Password) {
  int result = 0;
  int loopCounter = 0;
  WiFi.begin(WiFiName, Password);
  Serial.print("checking wifi " + WiFiName + "...");
  while (WiFi.status() != WL_CONNECTED && loopCounter <= 5) {
    Serial.print(" .");
    delay(1000);
    loopCounter++;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print ("Abandoning attempt to connect wifi " + WiFiName + ".");
    WiFi.disconnect();
    result = 0;
  }
  else {
    Serial.print ("Successfully connected wifi " + WiFiName + ".");
  }
  result = 1;
}


void loop() {
  // put your main code here, to run repeatedly:

}
