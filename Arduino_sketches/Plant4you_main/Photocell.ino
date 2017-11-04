int photocell_reading()
{
  int photocellReading = analogRead(photocellPin);
  // LED gets brighter the darker it is at the sensor
  // that means we have to -invert- the reading from 0-1023 back to 1023-0
  photocellReading = 1023 - photocellReading;
  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
  return photocellReading;
}

void photocell_out_serial_msg(int photocellReading)
{
  int range = map(photocellReading, sensorMin, sensorMax, 0, 3);
  // do something different depending on the range value:
  switch (range) {
    case 0:    // your hand is on the sensor
      Serial.println("dark");
      break;
    case 1:    // your hand is close to the sensor
      Serial.println("dim");
      break;
    case 2:    // your hand is a few inches from the sensor
      Serial.println("medium");
      break;
    case 3:    // your hand is nowhere near the sensor
      Serial.println("bright");
      break;
      }
}

void photocell_out_LED_brightness(int photocellReading)
{
  int LEDbrightness = map(photocellReading, sensorMin, sensorMax, 0, max_V);
  analogWrite(LEDpin, LEDbrightness);
}
