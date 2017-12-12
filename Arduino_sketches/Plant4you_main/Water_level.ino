 //watertank level check
void water_level_check()
{
  water_level = digitalRead(level_sensorPin);
  watertank_level_display(water_level);
  
  Serial.print("Water Level : "); Serial.println(water_level);
  Serial.println("-------------------------------");
}
  
void watertank_level_display(int water_level)
{
  if (Led1.progress == 0 && Led1.idx_color == WATER)
  {
     if (water_level == LOW) //the tank is empty, fast dimming
     {
      Led1.setColor(0,55,55); //aqua
     }
     else if (water_level == HIGH) // the tank has still water in it; slow dimming
     {
      Led1.setColor(0,5,70); //blue
     }
     Led1.idx_color= PHOTOCELL;
  }
}

void setup_level_sensor()
{
  pinMode(level_sensorPin, INPUT_PULLUP);
}

