
void watering_channel(int channel_nr)
{
  int moisturePin;
  int motorPin;
  int potPin;
    
  switch (channel_nr) {
    //--------------CHANEL 1--------------------
    case 0:
      moisturePin = moisturePin_channel1;
      motorPin = motorPin_channel1;
      potPin = pot_channel1;
      break;
    //--------------CHANEL 2--------------------
    case 1:
      moisturePin = moisturePin_channel2;
      motorPin = motorPin_channel2;
      potPin = pot_channel2;
      break;
    //--------------CHANEL 3--------------------
    case 2:
      moisturePin = moisturePin_channel3;
      motorPin = motorPin_channel3;
      potPin = pot_channel3;
      break;
    //--------------CHANEL 4--------------------
    case 3:
      moisturePin = moisturePin_channel4;
      motorPin = motorPin_channel4;
      potPin = pot_channel4;
      break;
  }

  int quantity_of_water = water_volume_check(potPin);
  int moisture = analogRead(moisturePin);
  
  Serial.print("pot value: ");
  Serial.println(quantity_of_water);
  Serial.print("moisture  value: ");
  Serial.println(moisture);
  
  //check if watering is necessary
  if (quantity_of_water > 16 && moisture > 1023)
  {
    Serial.print("MOTOR CHANNEL: ");Serial.print(channel_nr+1);Serial.println(" ON");
    
    digitalWrite(motorPin, HIGH);
    int i = 0;
  //for loop to increase time => watering duration in seconds
    while(i < (quantity_of_water-15))
    {
      i++;
      delay(1000); 
    }  
    
    digitalWrite(motorPin, LOW);
    
    
    
  }   
}

int water_volume_check(int potPin)
{
 int water_volume_Reading = analogRead(potPin);

 int water_volume = map(water_volume_Reading, Water_Volume_Value_Min, Water_Volume_Value_Max, 0, 100);

 return water_volume;
}

void setup_watering_system()
{
  //--------------CHANEL 1--------------------
  pinMode(motorPin_channel1, OUTPUT);
 pinMode(moisturePin_channel1, INPUT);
  pinMode(pot_channel1,INPUT);

  //--------------CHANEL 2--------------------
  pinMode(motorPin_channel2, OUTPUT);
  pinMode(moisturePin_channel2, INPUT);
  pinMode(pot_channel2,INPUT);
  
  //--------------CHANEL 3--------------------
  pinMode(motorPin_channel3, OUTPUT);
  pinMode(moisturePin_channel3, INPUT);
  pinMode(pot_channel3,INPUT);

  //--------------CHANEL 4--------------------
  pinMode(motorPin_channel4, OUTPUT);
  pinMode(moisturePin_channel4, INPUT);
  pinMode(pot_channel4,INPUT);
}
