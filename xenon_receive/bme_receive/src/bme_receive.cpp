/*
 * Project bme_receive
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"


void receivedData(const char *event, const char *data);
void logMessage(const char *event, const char *data);
void setup();
void loop();
#line 11 "c:/Users/dsmolych/Documents/bme_receive/bme_receive/src/bme_receive.ino"
void receivedData(const char *event, const char *data)
{
  Serial.printlnf("Event=%s Received data=%s", event, data ? data : NULL);
}


void logMessage(const char *event, const char *data)
{
  Serial.printlnf("%s", data);
}

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  Mesh.on();
  Mesh.connect();
  RGB.control(true);
  // If node has been successfully connected to Mesh Network RGB was green
  if(!Mesh.connecting())
    RGB.color(0, 255, 0);
  Mesh.subscribe("Sensor", receivedData);
  Mesh.subscribe("Log", logMessage);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}