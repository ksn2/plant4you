void alarm_activation()
{
  if ( battery_voltage = LOW || water_level == LOW)
  {
    //activation of PIR detector
    if (digitalRead(PIRPin) == LOW)
      activate_buzzer();

  Serial.print("PIR detector : "); Serial.println(digitalRead(PIRPin));
  Serial.println("-------------------------------");
  }
}

void activate_buzzer()
{
  tone(3,2048);
  delay(3000);
  noTone(3);
  //delay(2000);
}

void setup_alarm()
{
  pinMode(BuzzerPin, OUTPUT);
  pinMode(PIRPin, INPUT_PULLUP);
}

