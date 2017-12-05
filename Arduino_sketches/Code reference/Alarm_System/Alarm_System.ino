
int pirPin = 6; //motion detector pin
int ledPin = 13; //led pin

int pirState = LOW; //current pir state


//Setup the input and output pins
void setup(){
  Serial.begin(9600);
  
  pinMode(ledPin,OUTPUT);
  pinMode(pirPin,INPUT_PULLUP);
}


void loop(){

  //Get information from the motion detector
  pirState = digitalRead(pirPin);
  if (pirState==LOW)
  {
    Serial.println(" ------ON");
  }
  else {
    
  Serial.println("OFF------");
  }

  
digitalWrite(ledPin,pirState);
delay(200);


}
