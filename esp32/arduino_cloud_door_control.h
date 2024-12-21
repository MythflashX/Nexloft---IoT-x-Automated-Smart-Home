#ifndef ARDUINO_CLOUD_DOOR_CONTROL_H
#define ARDUINO_CLOUD_DOOR_CONTROL_H

#include <ESP32Servo.h>
#include "thingProperties.h"

Servo door_servo;
int servo_pin {13};
bool door_open {false};
bool door_close {false};

void arduino_cloud_door_control_setup ()
{
  door_servo.attach(servo_pin, 1000, 2000);
}

void onDoorChange ()
{
  if (door && !door_open) {
      door_servo.write(180);
      delay(300);
      door_servo.write(90);
      door_open = true;
      door_close = false;
      Serial.println("DOOR OPEN");
  }
  else if (!door && !door_close) {
    door_servo.write(0);
    delay(300);
    door_servo.write(90);
    door_open = false;
    door_close = true;
    Serial.println("DOOR CLOSE");
  }
  door_servo.write(90);
}

#endif