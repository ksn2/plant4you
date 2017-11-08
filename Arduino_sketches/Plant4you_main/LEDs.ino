

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
  int dimm=0;
   switch (color) {
   case 0:   
      setColor(max_V, 0, 0);  // red
      break;
      
   case 1:  
      setColor(0, max_V, 0);  // green
      break;
      
   case 2:    
      setColor(0, 0, max_V);  // blue
      break;
      
   case 3:   
      setColor(max_V, max_V, 0);  // yellow
      break;
      
   case 4:  
      setColor(52, 0, 52);  // purple
      break;
      
   case 5:    
      setColor(0, max_V, max_V);  // aqua
      break; 
       
   case 10:  
      while(dimm<max_V)
      {
        setColor(dimm, 0, 0);  // red
        delay(10);
        dimm++;
      }
      delay(10);
      while(dimm>0)
      {
        dimm--;
        setColor(dimm, 0, 0);  
        delay(10);
      }
      break;
      
   case 11:  
          while(dimm<max_V)
        {
          setColor(0, dimm, 0);  // green
          delay(10);
          dimm++;
        }
        while(dimm>0)
        {
          dimm--;
          setColor(0, dimm, 0);  
          delay(10);
        }
      break;
      
   case 12:   
      while(dimm<max_V)
      {
        setColor(0, 0, dimm);  // blue
        delay(10);
        dimm++;
      }
      delay(10);
      while(dimm>0)
      {
        dimm--;
        setColor(0 ,0, dimm);  
        delay(10);
      }
      break;   
  
  case 13:   
      while(dimm<max_V)
      {
        setColor(dimm, dimm, 0);  // not red
        delay(10);
        dimm++;
      }
      delay(10);
      while(dimm>0)
      {
        dimm--;
        setColor(dimm, dimm, 0);  
        delay(10);
      }
      break;   
  
  case 14:    
      while(dimm<max_V)
      {
        setColor(dimm, 0, dimm);  // not red
        delay(10);
        dimm++;
      }
      delay(10);
      while(dimm>0)
      {
        dimm--;
        setColor(dimm, 0, dimm);  
        delay(10);
      }
      break;   
  
  case 15:   
      while(dimm<max_V)
      {
        setColor(0, dimm, dimm);  // not red
        delay(10);
        dimm++;
      }
      delay(10);
      while(dimm>0)
      {
        dimm--;
        setColor(0, dimm, dimm);  
        delay(10);
      }
      break;
   }
}
