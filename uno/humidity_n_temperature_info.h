#ifndef HUMIDITY_N_TEMPERATURE_INFO_H
#define HUMIDITY_N_TEMPERATURE_INFO_H

#include <dht11.h>
//_____________________________________________________________- va[r]iables -
const int dhtpin {13};              // digital
int dhtread {0};
float humidity {0.0f};
float temperature {0.0f};
dht11 DHT11;
//_____________________________________________________________- fun[c]tions -
void humidity_n_temperature_info_setup ()
{

}

void humidity_n_temperature_info_loop ()
{
  dhtread = DHT11.read(dhtpin);
  temperature = DHT11.temperature;
  humidity = DHT11.humidity;

   //Serial.print("Humidity (%): ");
   //Serial.println(humidity, 2);

   //Serial.print("Temperature  (C): ");
   //Serial.println(temperature, 2);
}

#endif