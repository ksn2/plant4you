int current_photocell_value;
int mean_photocell_value;

void setup_photocell()
{
  pinMode(photocellPin, INPUT);
}

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
  int mean = brightness_mean_calculation();
  
  if(Led1.progress == 0 && Led1.idx_color ==500)
  {
    set_brightness_color(current_photocell_value);
    Led1.idx_color = 0;
  }
}

int brightness_mean_calculation()
{
  mean_photocell_value = (mean_photocell_value + current_photocell_value)/2;
  
  return mean_photocell_value;
}

void set_brightness_color(int brightness_mean)
{

  int brightness = map(brightness_mean, Photocell_Value_Min, Photocell_Value_Max, 0, 3);

  switch (brightness) {
   case 0:   
      Led1.setColorDimm(0,255,0);
      break;
   case 1:   
      Led1.setColorDimm(100,200,0);
      break;   
   case 2:   
      Led1.setColorDimm(200,100,0);
      break;   
   case 3:   
      Led1.setColorDimm(255,0,0);
      break;
  }
}

