#ifndef IOT_EXPORT_H
#define IOT_EXPORT_H

#include "fire_alarm.h"
#include "water_level_controller.h"
#include "humidity_n_temperature_info.h"
#include <string.h>
/*
int count{0};
int mapped_value {0};
void pseudo_water_level ()
{
  count++;
  if (count == 40)
    count = 0;

  mapped_value = map(count, 0, 40, 1, 100);
}
*/

void iot_export_loop ()
{
  //pseudo_water_level();
  String data {""};
  data += (int)temperature;
  data += ',';
  data += (int)humidity;
  data += ',';
  data += (100 - ((int)map(water_level, 0, 16, 1, 100)));
  data += ',';
  data += (int)fire_alarm_status;
  data += ',';
  data += "EOS";
  Serial.print(data);
  delay(1500);
}

#endif