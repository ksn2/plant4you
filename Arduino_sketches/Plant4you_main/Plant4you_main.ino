#include "Define.h"
#include "RGBLED.h"

int battery_voltage;
int water_level;

int current_photocell_value;
int mean_photocell_value;

RGBLED Led2(redPin1,greenPin1,bluePin1,COMMON_ANODE);
RGBLED Led1(redPin2,greenPin2,bluePin2,COMMON_ANODE);
  
void setup() 
{ 
  setup_alarm(); //(PIR, buzzer)
  setup_photocell();
  setup_level_sensor();
  
  setup_voltage_monitoring();
  setup_leds();
  setup_watering_system(); 
 
  Serial.begin(115200);
}

void loop() 
{

  Serial.println("-------------------------------");
  Serial.println("-------------------------------");
  Serial.println("-------------------------------");
  
  Led1.updateRGB();
  
  //define color to display on the RGB_LED2 depending on the water brightness mean value
  brightness_check();
  
  //watertank level check and display the color corresponding of the value read on the RGB_LED2
  water_level_check();
  
  //battery voltage  level check and display the color corresponding of the value read on the RGB_LED1  
  battery_voltage_check(); 
  
  //moisture check: if the moisture is too low the water pump will be activated
  Serial.println("--------------------------------");
  Serial.println("Channel1:");
  watering_channel(CHANNEL1);

  Serial.println("--------------------------------");
  Serial.println("Channel2:");
  watering_channel(CHANNEL2);

  Serial.println("--------------------------------");
  Serial.println("Channel3:");
  watering_channel(CHANNEL3);

  Serial.println("--------------------------------");
  Serial.println("Channel4:");
  watering_channel(CHANNEL4);
  Serial.println("--------------------------------");

  
  //activation of PIR detector and buzzer if necessary
  alarm_activation();

  delay(5);
}

void setup_leds()
{

  //----------------LED1----------------------------//
  pinMode(redPin1,OUTPUT);
  pinMode(greenPin1,OUTPUT);
  pinMode(bluePin1,OUTPUT);
  
  Led1.turnOff();


  //----------------LED2----------------------------//
  pinMode(redPin2,OUTPUT);
  pinMode(greenPin1,OUTPUT);
  pinMode(bluePin1,OUTPUT);
  
  Led2.turnOff();
}



