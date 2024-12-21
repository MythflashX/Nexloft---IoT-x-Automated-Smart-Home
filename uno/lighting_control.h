#ifndef LIGHTING_CONTROL_H
#define LIGHTING_CONTROL_H

//_____________________________________________________________- va[r]iables -
const int motion_sensor_pin {8};          // digital
const int pir_light_pin {9};              // digital
const int ldr_pin {10};                   // digital
const int ldr_light_pin_batch1 {11};      // digital
const int ldr_light_pin_batch2 {12};      // digital
int timer_count {0};
int reset_counter {0};
bool timer_start {false};
//_____________________________________________________________- fun[c]tions -
void timer ();
void ldr_output_control ();
void pir_output_control ();

void lighting_control_setup ()
{
  pinMode(pir_light_pin, OUTPUT);
  pinMode(ldr_light_pin_batch1, OUTPUT);
  pinMode(ldr_light_pin_batch2, OUTPUT);
  pinMode(ldr_pin, INPUT);
  pinMode(motion_sensor_pin, INPUT);
}

void lighting_control_loop ()
{
   //Serial.print("Lighting Control Info : ");
   //Serial.print(timer_count);
   //Serial.print(" : ");
   //Serial.println(reset_counter);
  timer_count++;
  pir_output_control();
  ldr_output_control();
}

void ldr_output_control ()
{
  if (digitalRead(ldr_pin)) {
    digitalWrite(ldr_light_pin_batch1, HIGH);
    digitalWrite(ldr_light_pin_batch2, HIGH);
  }
  else {
    digitalWrite(ldr_light_pin_batch1, LOW);
    digitalWrite(ldr_light_pin_batch2, LOW);
  }
}

void pir_output_control ()
{
  if (timer_count == 40) {                                          // restart the timer
    timer_count = 0;
  }

  if (digitalRead(motion_sensor_pin)) {                             // start the timer if motion is detected
    timer_start = true;
    reset_counter = 0;
    digitalWrite(pir_light_pin, HIGH);
  }

  if (((timer_count % 2) == 0) && (timer_count != 0)) {             // check every 5 seconds
    //Serial.println("\t\t CHECK \t\t");
    if (!digitalRead(motion_sensor_pin)) {                          // timer will advance until it senses another motion or until it expires
      reset_counter++; timer_count++;
    }
    else {
      reset_counter = 0;                                            // restart the timer upon sensing another motion                             
    }
  }

  if (reset_counter >= 2) {                                         // if timer expires without sensing addition motion...lights will go off
    digitalWrite(pir_light_pin, LOW);
  }
}

#endif