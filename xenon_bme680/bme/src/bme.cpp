#include "Particle.h"
#include "Adafruit_BME680.h"

void setup();
void loop();
void getTemp();
#line 4 "c:/Users/dsmolych/Documents/bme/bme/src/bme.ino"
#define THRESHOLD 27.0f
#define ASK_PERIOD 2000

Adafruit_BME680 bme;
Timer askTimer(ASK_PERIOD, getTemp);

float temp = 0.0;

void setup()
{
  //Serial.begin(9600);
  RGB.control(true);
  if(bme.begin(BME680_I2C_ADDR_PRIMARY))
    askTimer.start(); // Start ask timer
  else
    RGB.color(255, 0, 0);
  Mesh.on();
  Mesh.connect();
}


void loop()
{
  /*if (! bme.performReading()) {
    Mesh.publish("Log", "Failed to perform reading :(");
  } else {
    temp = bme.temperature;*/

    // Verify our threshold and indicate it with LED on board
    if(temp > THRESHOLD)
      RGB.color(255, 0, 0);
    else 
      RGB.color(0, 0, 255);

    /*String data = String::format(
      "{"
        "\"temperature\":%.1f"
      "}",
      temp);

    Mesh.publish("Sensor", data);*/
  
  //}
  //delay(2 * 1000);
}


void getTemp()
{
  if(! bme.performReading())
    Mesh.publish("Log", "Failed to perform reading.");
  else
  {
    temp = bme.temperature;
    String data = String::format(
    "{"
      "\"temperature\":%.1f"
    "}",
    temp);
    Mesh.publish("Sensor", data);
  }
}