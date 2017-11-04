/*
Adafruit Arduino - Lesson 3. RGB LED
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
#define max_V 160

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop()
{
  setColor(max_V, 0, 0);  // red
  delay(1000);
  setColor(0, max_V, 0);  // green
  delay(1000);
  setColor(0, 0, max_V);  // blue
  delay(1000);
  setColor(max_V, max_V, 0);  // yellow
  delay(1000);  
  setColor(52, 0, 52);  // purple
  delay(1000);
  setColor(0, max_V, max_V);  // aqua
  delay(1000);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
