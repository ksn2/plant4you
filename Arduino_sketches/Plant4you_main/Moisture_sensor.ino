#define PIN_MOTOR1 00
#define PIN_MOTOR2 00
#define PIN_MOTOR3 00
#define PIN_MOTOR4 00

int soil_moisture_read(int sensor_nr)
{
  int moisturePin=0;
  switch(sensor_nr){
  case 0:
    moisturePin=A1;
    break;

  case 1:
    moisturePin=A2;
    break;

  case 2:
    moisturePin=A3;
    break;

  case 3:
    moisturePin=A4;
    break;
  }
  
  int moistureReading = analogRead(moisturePin);
  return moistureReading;  
}

void moisture_level_check_value(int moisture_level,int motor_nr)
{
  int motorPin;  
  switch(motor_nr){
  case 0:
    motorPin=PIN_MOTOR1;
    break;

  case 1:
    motorPin=PIN_MOTOR2;
    break;

  case 2:
    motorPin=PIN_MOTOR3;
    break;

  case 3:
    motorPin=PIN_MOTOR4;
    break;
  }
  
  int moisture = map(moisture_level, sensorMin2, sensorMax2, 0, 1);
  Serial.println(moisture);
  if (moisture==0)
  {
    //set motor for 
    analogWrite(moisture_LED, max_V); 
    delay(500);
    analogWrite(moisture_LED,0); 
  }
  else{
    analogWrite(moisture_LED,0);
    //do nothing
  }
}
