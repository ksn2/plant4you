

void RGB_LEDs_setup()
{ 
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void RGB_LEDs_color_show()
{
  setColor(max_V, 0, 0);  // red
  delay(1000);
  setColor(0, max_V, 0);  // green
  delay(1000);
  setColor(0, 0, max_V);  // blue
  delay(1000);
  setColor(max_V, max_V, 0);  // yellow
  delay(1000);  
  setColor(purple_idx, 0, purple_idx);  // purple
  delay(1000);
  setColor(0, max_V, max_V);  // aqua
  delay(1000);
}

//color + DIMMING effect
void setColor1(int color)
{
   switch (color) {
   case 0:    // your hand is on the sensor
      setColor(max_V, 0, 0);  // red
      break;
      
   case 1:    // your hand is on the sensor
      setColor(0, max_V, 0);  // green
      break;
      
   case 2:    // your hand is on the sensor
      setColor(0, 0, max_V);  // blue
      break;
      
   case 3:    // your hand is on the sensor
      setColor(max_V, max_V, 0);  // yellow
      break;
      
   case 4:    // your hand is on the sensor
      setColor(52, 0, 52);  // purple
      break;
      
   case 5:    // your hand is on the sensor
      setColor(0, max_V, max_V);  // aqua
      break; 
       
   case 100:    // your hand is on the sensor
      for(int i=0;i++;i<max_V)
      {
        setColor(i, 0, 0);  // red
      }
      delay(1);
      for(int i=max_V;i--;i>0)
      {
        setColor(i, 0, 0);  // red
      }
      break;
      
   case 101:    // your hand is on the sensor
      for(int i=0;i++;i<max_V)
      {
        setColor(0, i, 0);  // red
      }
      delay(1);
      for(int i=max_V;i--;i>0)
      {
        setColor(0, i, 0);  // red
      }
      break;
      
   case 102:    // your hand is on the sensor
      
      for(int i=0;i++;i<max_V)
      {
        setColor(0, 0, i);  // red
      }
      delay(1);
      for(int i=max_V;i--;i>0)
      {
        setColor(0, 0, i);  // red
      }
      break;
      
   case 103:    // your hand is on the sensor

      for(int i=0;i++;i<max_V)
      {
        setColor(i, i, 0);  // red
      }
      delay(1);
      for(int i=max_V;i--;i>0)
      {
        setColor(i, i, 0);  // red
      }
      break;
      
   case 104:    // your hand is on the sensor
     
      for(int i=0;i++;i<purple_idx)
      {
        setColor(i, 0, i);  // red
      }
      delay(1);
      for(int i=purple_idx;i--;i>0)
      {
        setColor(i, 0, i);  // red
      }
      break;
      
   case 105:    // your hand is on the sensor
      
      for(int i=0;i++;i<max_V)
      {
        setColor(0, i, i);  // red
      }
      delay(1);
      for(int i=max_V;i--;i>0)
      {
        setColor(0, i, i);  // red
      }
      break;     
      }
}
