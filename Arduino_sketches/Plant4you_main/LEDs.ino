void led_update_color()
{
  Led1.dimmRGB();
  //Led2.dimmRGB();
  int progress = Led1.progress;
  
  //if (PIRstate==0 || water_level==0)
   //Led1.idx_color=200;
   
//    if (Led1.progress== 0 && Led1.idx_color==0)
//  {
//    Led1.setColorDimm(0,255,0);
//    Led1.idx_color =100;
//  }
//  if ( Led1.progress == 0 && Led1.idx_color==100)
//  {
//    Led1.setColorDimm(0,0,255);
//    Led1.idx_color=0;
//  }
//
//if ( Led1.progress == 0 && Led1.idx_color==200)
//  {
//    Led1.setColorDimm(255,0,0);
//    Led1.idx_color =0;
//  }
  delay(10);
}

void setup_RGB_LED1()
{ 
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT); 
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin1, red);
  analogWrite(greenPin1, green);
  analogWrite(bluePin1, blue);  
}

//color + DIMMING effect
void setColor_LED1(int color)
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
