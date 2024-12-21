#ifndef THINGPROPERTIES_H
#define THINGPROPERTIES_H

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "ARDUINO_IoT_DEVICE_LOGIN_NAME";
const char DEVICE_KEY[]         = "ARDUINO_IoT_DEVICE_KEY";    // Secret device password
const char SSID[]               = "Your_WiFi_SSID";    // Network SSID (name)
const char PASS[]               = "YOUR_WiFi_PASS";    // Network password (use for WPA, or use as key for WEP)


void print ();
void lights_control ();
void onDoorChange ();
void onStatusChange ();
void onLightIdChange ();
void onLightSwitchChange ();
void onMainSwitchChange ();
void onDoorChange();

int light_id;
bool light_switch;
bool status;
bool door;
bool main_switch;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(light_id, READWRITE, ON_CHANGE, onLightIdChange, 5);
  ArduinoCloud.addProperty(light_switch, READWRITE, ON_CHANGE, onLightSwitchChange);
  ArduinoCloud.addProperty(status, READWRITE, ON_CHANGE, onStatusChange);
  ArduinoCloud.addProperty(door, READWRITE, ON_CHANGE, onDoorChange);
  ArduinoCloud.addProperty(main_switch, READWRITE, ON_CHANGE, onMainSwitchChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

#endif
