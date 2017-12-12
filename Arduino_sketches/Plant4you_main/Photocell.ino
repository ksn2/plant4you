
int photocell_reading()
{
  int photocellReading = analogRead(photocellPin);
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  return photocellReading;
}


//edit the current value of the photocell
void brightness_check()
{
  current_photocell_value = photocell_reading();
  mean_photocell_value = (mean_photocell_value + current_photocell_value)/2;

  Serial.print("Brightness : "); Serial.println(current_photocell_value);
  Serial.print("Brightness  mean: "); Serial.println(mean_photocell_value);
  Serial.println("-------------------------------");
  
  if(Led1.progress == 0 && Led1.idx_color == PHOTOCELL)
  {
    set_brightness_color(current_photocell_value);
    Led1.idx_color = WATER;
  }
}


void set_brightness_color(int brightness_mean)
{

  int brightness = map(brightness_mean, Photocell_Value_Min, Photocell_Value_Max, 0, 3);

  switch (brightness) {
   case 0:   
      Led1.setColor(0,150,0);
      break;
   case 1:   
      Led1.setColor(80,150,0);
      break;   
   case 2:   
      Led1.setColor(150,80,0);
      break;   
   case 3:   
      Led1.setColor(150,0,0);
      break;
  }
}


void setup_photocell()
{
  pinMode(photocellPin, INPUT);
}

