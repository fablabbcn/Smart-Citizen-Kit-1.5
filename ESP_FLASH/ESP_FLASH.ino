#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include "Constants.h"
#include "SCKDrivers.h"

SCKDriver driver;

#define USBEnabled      true 
#define sensorEnabled   true
#define debuggEnabled   false

uint32_t timetransmit = 0;  
uint32_t TimeUpdate   = 0;  //Variable temporal de tiempo entre actualizacion y actualizacion de los sensensores
uint32_t NumUpdates   = 0;  //Numero de actualizaciones antes de postear

File myFile;

uint32_t SENSORvalue[20];

void setup() {
  delay(5000);
  sckBegin();
  sckAccelDefault();
  sckConfig();
  driver.ESPflash();
  //driver.ESPini();
}

void loop() {  
  if (Serial.available())
      SerialUSB.write(Serial.read());
  if (SerialUSB.available())
    Serial.write(SerialUSB.read());
}
