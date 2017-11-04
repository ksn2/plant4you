
int photocellPin = A0;     // the cell and 10K pulldown are connected to a0

int LEDpin = 12;          // connect Red LED to pin 11 (PWM pin)
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int moisture_LED = 13;

#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3
#define PURPLE 4
#define AQUA 5
#define DIMMING 100

#define SENSOR1 0
#define SENSOR2 1
#define SENSOR3 2
#define SENSOR4 3

#define max_V 168
#define purple_idx 52
#define sensorMin 0
#define sensorMax 1023

void setup() 
{
  Serial.begin(9600);
  RGB_LEDs_setup();
}

void loop() 
{
  int photocellReading = photocell_reading();
  photocell_out_LED_brightness(photocellReading);
  photocell_out_serial_msg(photocellReading);

  setColor1(RED);
  setColor1(BLUE);
  setColor1(GREEN);
  setColor1(YELLOW);
  setColor1(PURPLE);
  setColor1(AQUA);

  setColor1(RED+DIMMING);
  setColor1(BLUE+DIMMING);
  setColor1(GREEN+DIMMING);
  
  int moisture_level=soil_moisture_read(SENSOR1); 
  moisture_level_check_value(moisture_level,SENSOR1);
  
}




