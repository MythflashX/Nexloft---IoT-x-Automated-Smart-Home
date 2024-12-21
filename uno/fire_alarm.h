#ifndef FIRE_ALARM_H
#define FIRE_ALARM_H

//_____________________________________________________________- va[r]iables -
const int buzzer_pin {2};             // digital            
const int flame_sensor_pin {3};       // digital
const int gas_sensor_pin {A0};        // analog
const int gas_threshold {20};
bool fire_alarm_status {false};

//_____________________________________________________________- fun[c]tions -
void fire_alarm_setup ()
{
  pinMode(buzzer_pin, OUTPUT);
  pinMode(gas_sensor_pin, INPUT);
  pinMode(flame_sensor_pin, INPUT);
}

void fire_alarm_loop ()
{
  int detected_gas {analogRead(gas_sensor_pin)};
  bool detected_flame {digitalRead(flame_sensor_pin)};      // flame detection > LOW | no flame detection > HIGH...yeh it is in reverse
   // Serial.println("Fire alarm Info : ");
   // Serial.println(detected_gas);
   // Serial.println(detected_flame);

  if ((detected_gas > gas_threshold) && (detected_flame == LOW)) {
    tone(buzzer_pin, 5000);   fire_alarm_status = true;
  }
  else {
    noTone(buzzer_pin);       fire_alarm_status = false;
  }
}

#endif