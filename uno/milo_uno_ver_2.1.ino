#include "fire_alarm.h"
#include "water_level_controller.h"
#include "lighting_control.h"
#include "humidity_n_temperature_info.h"
#include "iot_export.h"

void setup ()
{
  Serial.begin(9600);
  fire_alarm_setup();
  water_level_controller_setup();
  lighting_control_setup();
  humidity_n_temperature_info_setup();
}

void loop ()
{
  fire_alarm_loop();
  water_level_controller_loop();
  lighting_control_loop();
  humidity_n_temperature_info_loop();
  iot_export_loop();
}