#ifndef ARDUINO_CLOUD_LIGHTS_CONTROL_H
#define ARDUINO_CLOUD_LIGHTS_CONTROL_H

#include "thingProperties.h"

int fir {14};
int sec {26};
int thi {33};
int fou {15};
int fif {18};
int six {21};
int sev {27};
int eig {25};
int nin {32};
int ten {19};

int light_array[10] {fir, sec, thi, fou, fif, six, sev, eig, nin, ten};
bool switch_array[10] {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};

void onLightIdChange () { };
void onLightSwitchChange () { };
void onMainSwitchChange () { };
void onStatusChange()  
{
  status = switch_array[light_id];
  light_switch = switch_array[light_id];
}

void arduino_cloud_lights_control_setup ()
{
  for (int index{0}; index < 10; index++)
    pinMode(light_array[index], OUTPUT);
}

void lights_control ()
{
  if (light_switch) {
    switch_array[light_id] = HIGH;
    digitalWrite(light_array[light_id], HIGH);
  }
  else {
    switch_array[light_id] = LOW;
    digitalWrite(light_array[light_id], LOW);
  }
}

void print ()
{
  for (int index{0}; index < 10; index++)
  {
    Serial.print(light_array[index]);
    Serial.print(" : ");
    Serial.print(switch_array[index]);
    Serial.print(" | ");  
  }
    Serial.println (" ");
}

#endif