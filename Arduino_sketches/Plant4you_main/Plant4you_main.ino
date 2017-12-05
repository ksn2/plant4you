#include "Define.h"
#include "LowPower.h"
#include "RGBLED.h"

int battery_voltage;
int water_level;


RGBLED Led2(12,13,14,COMMON_CATHODE);
RGBLED Led1(11,10,9,COMMON_CATHODE);
  
void setup() 
{ 
  setup_alarm(); //(PIR, buzzer)
  setup_voltage_monitoring();
  setup_photocell();
  setup_level_sensor();
  setup_watering_system();
  
  pinMode(voltage_ctrlPin,OUTPUT);
  digitalWrite(voltage_ctrlPin, HIGH);
  
  //Led1.setColorDimm(255,255,255);
 
  Serial.begin(9600);
  
}

void loop() 
{
  led_update_color();

  //define color to display on the RGB_LED2 depending on the water brightness mean value
  brightness_check();
  //watertank level check and display the color corresponding of the value read on the RGB_LED2
  water_level_check();
  //battery voltage  level check and display the color corresponding of the value read on the RGB_LED1  
  battery_voltage_check(); 
  
  //moisture check: if the moisture is too low the water pump will be activated
  watering_channel(CHANNEL1);
  watering_channel(CHANNEL2);
  watering_channel(CHANNEL3);
  watering_channel(CHANNEL4);

  //activation of PIR detector and buzzer if necessary
  alarm_activation();
}




