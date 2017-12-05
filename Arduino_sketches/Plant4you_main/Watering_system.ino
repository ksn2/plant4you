
void watering_channel(int channel_nr)
{
  int moisturePin;
  int motorPin;
  int potPin;
    
  switch (channel_nr) {
    case 0:
      moisturePin = moisturePin_channel1;
      motorPin = motorPin_channel1;
      potPin = pot_channel1;
      break;

    case 1:
      moisturePin = moisturePin_channel2;
      motorPin = motorPin_channel2;
      potPin = pot_channel2;
      break;

    case 2:
      moisturePin = moisturePin_channel3;
      motorPin = motorPin_channel3;
      potPin = pot_channel3;
      break;

    case 3:
      moisturePin = moisturePin_channel4;
      motorPin = motorPin_channel4;
      potPin = pot_channel4;
      break;
  }

  int quantity_of_water = analogRead(potPin);
  int moisture = moisture_check(moisturePin);
  
  if (quantity_of_water > 10 && moisture==0)
  {
    int watering_duration = set_watering_duration(quantity_of_water);
    watering(motorPin, watering_duration);
  }   
}

int moisture_check(int moisturePin)
{
 int moistureReading = analogRead(moisturePin);

 int moisture = map(moistureReading, Moisture_Value_Min, Moisture_Value_Max, 0, 1);

 return moisture;
}

void watering( int motorPin, int watering_duration)
{
  digitalWrite(motorPin, HIGH);
  for( int i=0; i++; i<10)
  {
    delay(watering_duration*10);
  }
  digitalWrite(motorPin, LOW);
}

int set_watering_duration(int quantity_of_water)
{
  //check user parameter
  int watering_duration = map(quantity_of_water, Pot_Value_Min, Pot_Value_Max, 0, 10);
  
 return watering_duration;
}


void setup_watering_system()
{
  //--------------CHANELL 1--------------------
  pinMode(motorPin_channel1, OUTPUT);
  pinMode(moisturePin_channel1, INPUT);
  pinMode(pot_channel1,INPUT);

  //--------------CHANELL 2--------------------
  pinMode(motorPin_channel2, OUTPUT);
  pinMode(moisturePin_channel2, INPUT);
  pinMode(pot_channel2,INPUT);
  //--------------CHANELL 3--------------------
  pinMode(motorPin_channel3, OUTPUT);
  pinMode(moisturePin_channel3, INPUT);
  pinMode(pot_channel3,INPUT);

  //--------------CHANELL 4--------------------
  pinMode(motorPin_channel4, OUTPUT);
  pinMode(moisturePin_channel4, INPUT);
  pinMode(pot_channel4,INPUT);
}
