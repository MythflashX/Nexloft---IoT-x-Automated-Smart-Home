#ifndef WATER_LEVEL_CONTROLLER_H
#define WATER_LEVEL_CONTROLLER_H

//_____________________________________________________________- va[r]iables -
const int echo_pin {4};             // digital
const int trigger_pin {5};          // digital
const int motor_pin_firdir {6};     // digital      first direction
const int motor_pin_secdir {7};     // digital      second direction

float detected_duration {0};
float water_level {0};
float base_level {15};
float lower_level {10};
float upper_level {3};
//_____________________________________________________________- fun[c]tions -
void trigger ()
{
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
}

void water_level_controller_setup ()
{
  pinMode(trigger_pin, OUTPUT);
  pinMode(motor_pin_firdir, OUTPUT);
  pinMode(motor_pin_secdir, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void water_level_controller_loop ()
{                                  
  trigger();                                                          // generate ultrasonic wave every 10 microseconds
  detected_duration = pulseIn(echo_pin, HIGH);
  water_level = ((detected_duration * 0.0343) / 2);
  // Serial.print("Water Level Controller Info : ");
  //Serial.println(water_level);

  if (water_level >= base_level || water_level >= lower_level) {
    digitalWrite(motor_pin_firdir, HIGH);
    digitalWrite(motor_pin_secdir, LOW);
  }
  else if (water_level <= upper_level) {
    digitalWrite(motor_pin_firdir, LOW);
    digitalWrite(motor_pin_secdir, LOW);
  }
}

#endif