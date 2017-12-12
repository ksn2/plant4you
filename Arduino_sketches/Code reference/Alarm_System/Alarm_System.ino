
int pirPin = 17; //motion detector pin
int ledPin = 7; //led pin

int pirState = LOW; //current pir state


//Setup the input and output pins
void setup(){
  Serial.begin(9600);
  
  pinMode(ledPin,OUTPUT);
  pinMode(pirPin,INPUT_PULLUP);
  digitalWrite(ledPin,HIGH);
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


delay(200);


}
