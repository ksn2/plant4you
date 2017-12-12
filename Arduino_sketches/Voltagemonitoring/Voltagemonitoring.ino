/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {

  pinMode(3,OUTPUT);
  pinMode(8,OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A5);
  // print out the value you read:
  Serial.print("Voltage Level:");
  Serial.println(sensorValue);
  float f_sensorValue= 3.33*sensorValue/1023*2;
  Serial.println(f_sensorValue);
  digitalWrite(8,HIGH);
  tone(3,1000);
  delay(5000);        // delay in between reads for stability
  noTone(3);
  delay(2000);

}
