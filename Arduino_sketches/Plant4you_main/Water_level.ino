 //watertank level check
void water_level_check()
{
  water_level = digitalRead(level_sensorPin);
  watertank_level_display(water_level);
}
  
void watertank_level_display(int water_level)
{
  if (Led1.progress==0 && Led1.idx_color==0)
  {
     if (water_level == LOW) //the tank is empty, fast dimming
     {
      Led1.setColorDimm(0,55,55); //aqua
     }
     else if (water_level == HIGH) // the tank has still water in it; slow dimming
     {
      Led1.setColorDimm(0,10,200); //blue
     }
     Led1.idx_color= 500;
  }
}

void setup_level_sensor()
{
  pinMode(level_sensorPin, INPUT_PULLUP);
}

