#ifndef STATUS_MONITOR_H
#define STATUS_MONITOR_H

#include <string.h>

int data_stream[] {0, 0, 0, 0, 0};

void strtoint_converter (String buffer, int& intval)
{
  //Serial.println("strtoint_converter");
  //Serial.println(buffer);
  intval = 0;
  int index {0};
  while (buffer[index] != '\0') 
  {
    switch (buffer[index])
    {
      case '0': (index != 1) ? intval += 0 : intval += 0;         break;
      case '1': (index != 1) ? intval += 10 : intval += 1;        break;
      case '2': (index != 1) ? intval += 20 : intval += 2;        break;
      case '3': (index != 1) ? intval += 30 : intval += 3;        break;
      case '4': (index != 1) ? intval += 40 : intval += 4;        break;
      case '5': (index != 1) ? intval += 50 : intval += 5;        break;
      case '6': (index != 1) ? intval += 60 : intval += 6;        break;
      case '7': (index != 1) ? intval += 70 : intval += 7;        break;
      case '8': (index != 1) ? intval += 80 : intval += 8;        break;
      case '9': (index != 1) ? intval += 90 : intval += 9;        break;
    }
    index++;
  }
  //Serial.println(intval);
}

void decode_string (String raw_information)
{
  int advance {0};
  int index {0};
  String buffer {""};
  while (raw_information[advance] != '\0') 
  {
    if (raw_information[advance] != ',') {
      buffer += raw_information[advance];
    }
    else if (raw_information[advance] == ',') {
      strtoint_converter(buffer, data_stream[index]);
      buffer = "";
      index++;
      //Serial.println(data_stream[index]);
    }
    //Serial.println(raw_information[advance]);
    advance++;
  }
}

void status_monitor_loop ()
{
  String incoming_information {Serial2.readString()};
  decode_string (incoming_information);
  Serial.println("Status Monitor");
  Serial.println(incoming_information);

  for (int count{0}; count < 5; count++)
    Serial.println(data_stream[count]);

  Blynk.virtualWrite(V0, data_stream[0]);
  Blynk.virtualWrite(V1, data_stream[1]);
  Blynk.virtualWrite(V2, data_stream[2]);
  Blynk.virtualWrite(V3, data_stream[3]);
}

void message_loop ()
{
  Serial.println("MESSAGE RECEIVED: ");
  Serial.println(Serial2.readString());
}

#endif