void alarm_activation()
{
  if ( battery_voltage = LOW || water_level == LOW)
  {
    //activation of PIR detector
    if (digitalRead(PIRPin) == LOW)
      activate_buzzer();
  }
}

void activate_buzzer()
{
//      digitalWrite(BuzzerPin, HIGH);
//      delay(800);
//      digitalWrite(BuzzerPin, LOW);
//      delay(800);
//      digitalWrite(BuzzerPin, HIGH);
//      delay(800);
//      digitalWrite(BuzzerPin, LOW);
//      delay(800);
//      digitalWrite(BuzzerPin, HIGH);
//      delay(800);
//      digitalWrite(BuzzerPin, LOW);
}

void setup_alarm()
{
  pinMode(BuzzerPin, OUTPUT);
  pinMode(PIRPin, INPUT_PULLUP);
}

