
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
#define DIMMING 10

#define SENSOR1 0
#define SENSOR2 1
#define SENSOR3 2
#define SENSOR4 3

#define max_V 168
#define purple_idx 52
#define sensorMin 200
#define sensorMax 700
#define sensorMin2 0
#define sensorMax2 500

void setup() 
{
  Serial.begin(9600);
  RGB_LEDs_setup();
}

void loop() 
{
  int photocellReading = photocell_reading();
  photocell_out_LED_brightness(photocellReading);
  //photocell_out_serial_msg(photocellReading);
  delay(500);

//  setColor1(RED);
//  delay(500);
//  setColor1(BLUE);
//  delay(500);
//  setColor1(GREEN);
//  delay(500);
//  setColor1(YELLOW);
//  delay(500);
//  setColor1(PURPLE);
//  delay(500);
//  setColor1(AQUA);

  //setColor1(RED+DIMMING);
  //setColor1(BLUE+DIMMING);
  //setColor1(GREEN+DIMMING);
//  setColor1(YELLOW+DIMMING);
//  setColor1(PURPLE+DIMMING);
 // setColor1(AQUA+DIMMING);


  int sensorValue = analogRead(A5);
  //Serial.println(sensorValue);
 
 
  int moisture_level=soil_moisture_read(SENSOR1); 
  Serial.println(moisture_level);
  moisture_level_check_value(moisture_level,SENSOR1);
  
}




