
//------------------------PHOTOCELL-------------------------------------//
void photocell_out_serial_msg(int photocellReading)
{
  int range = map(photocellReading, Photocell_Value_Min, Photocell_Value_Max, 0, 3);
     // Serial.println(photocellReading);
  // do something different depending on the range value:
  switch (range) {
    case 0:    // your hand is on the sensor
      Serial.println("bright");
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("medium");
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("dim");
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("dark");
      break;
      }
}

void photocell_out_LED_brightness(int photocellReading)
{
  int LEDbrightness = map(photocellReading, Photocell_Value_Min, Photocell_Value_Max, 0, max_V);
  //analogWrite(LEDpin, LEDbrightness);
}


//------------------------LED-------------------------------------//
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
