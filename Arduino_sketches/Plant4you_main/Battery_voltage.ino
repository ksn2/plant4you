 //battery voltage check


void battery_voltage_check()
{
  battery_voltage = analogRead(batteryVoltagePin);
  float voltage = battery_voltage;
  voltage = 3.33*voltage/1023*2;
  
  Serial.print("Battery Voltage : ");  Serial.println(voltage);
  
  battery_voltage_display(battery_voltage);
  if(Led2.progress < 10)
  {
    Led2.writeRGB(0,0,0);
  }
}
  
void battery_voltage_display(int voltage)
{
    int battery_level = map(voltage, Battery_Voltage_Min, Battery_Voltage_Max, 0, 3);
    
    Serial.print("Battery_level : "); Serial.println(battery_level);
    
    battery_level==0 ? battery_voltage = LOW : battery_voltage = HIGH;//set LED color    
  
  switch (battery_level) {
   case 0:   
      Led2.writeRGB(30,0,0);
      break;
   case 1:   
      Led2.writeRGB(255,255,0);
      break;   
   case 2:   
      Led2.writeRGB(50,255,0);
      break;   
   case 3:   
      Led2.writeRGB(0,255,0);
      break;
  }
}

void setup_voltage_monitoring()
{
  pinMode(batteryVoltagePin, INPUT);
}

