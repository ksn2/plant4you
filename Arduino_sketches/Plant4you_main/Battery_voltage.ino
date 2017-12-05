 //battery voltage check


void battery_voltage_check()
{
  battery_voltage = analogRead(batteryVoltagePin);
  if(Led2.progress==0)
  battery_voltage_display(battery_voltage);
}
  
void battery_voltage_display(int voltage)
{
    int battery_level = map(voltage, Battery_Voltage_Min, Battery_Voltage_Max, 0, 3);
    
    battery_level==0 ? battery_voltage = LOW : battery_voltage = HIGH;//set LED color
      
  switch (battery_level) {
   case 0:   
      Led2.setColorDimm(255,0,0);
      break;
   case 1:   
      Led2.setColorDimm(255,20,0);
      //delay(1);
      break;   
   case 2:   
      Led2.setColorDimm(255,100,0);
      //delay(5);
      break;   
   case 3:   
      Led2.setColorDimm(0,255,0);
      //delay(10);
      break;
  }
}

void setup_voltage_monitoring()
{
  pinMode(batteryVoltagePin, INPUT);
}

