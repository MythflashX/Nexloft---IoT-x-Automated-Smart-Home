//------------------------------ ex[T]ernal fi[L]es ------------------------------//
//_____________________________________________________________________________________________ - bl[Y]nk cl[O]ud -
#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH TOKEN"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "status_monitor.h"

char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Pass";
const int RXp2 {16};
const int TXp2 {17};
//_____________________________________________________________________________________________ - ard[U]ino cl[O]ud -
#include "arduino_cloud_lights_control.h"
#include "arduino_cloud_door_control.h"

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  delay(1500);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  arduino_cloud_lights_control_setup();
  arduino_cloud_door_control_setup();
}

void loop() {
  Blynk.run();
  ArduinoCloud.update();
  lights_control();
  onStatusChange();
  onDoorChange();
  print();
  status_monitor_loop();
}