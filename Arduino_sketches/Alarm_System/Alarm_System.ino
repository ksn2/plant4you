//Buzzer code structure adapted from code on http://mertarduinotutorial.blogspot.com.tr/2016/11/buzzer-button-melody.html 
//Alarm System
//By: Andrew Johnson

#include "pitches.h"  //add note library

int buzzerPin = 8; //piezo buzzer pin
int micPin = 7; //sound detector pin
int pirPin = 6; //motion detector pin
int ledPin = 13; //led pin

int pirState = LOW; //current pir state
int micState = LOW; //current mic value
int alarmState = LOW; //current alarm state

int noteDuration = 0;
int pauseBetweenNotes = 0;

//Notes in the buzzer melody
int melody[]={NOTE_C8, NOTE_C8, NOTE_C8, NOTE_C8, NOTE_C8, NOTE_C8};

//Buzzer note durations. 4=quarter note / 8=eighth note
int noteDurations[]={4, 9, 9, 9, 4, 4};


//Turn the alarm on or off
void setAlarm(String value){
  //If the alarm is turned on, activate the led and the buzzer sequence
  if(value.equals("ON")){
    digitalWrite(ledPin, HIGH);
    
    //Iterate over the notes of the melody
    for (int thisNote=0; thisNote < 6; thisNote++){

      //To calculate the note duration, take one second. Divided by the note type
      noteDuration = 1000 / noteDurations [thisNote];
      tone(8, melody [thisNote], noteDuration);

      //To distinguish the notes, set a minimum time between them
      //The note's duration +30% seems to work well
      pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);  
    }  
  }

  //If the alarm is turned off, deactivate the led and buzzer melody
  else{
    digitalWrite(ledPin, LOW);
    //stop the tone playing
    noTone(buzzerPin);
  }
}

//Setup the input and output pins
void setup(){
  pinMode(buzzerPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(pirPin,INPUT);
  pinMode(micPin,INPUT);
}


void loop(){

  //Get information from the motion detector
  pirState = digitalRead(pirPin);
  //Get information from the sound sensor
  micState = digitalRead(micPin);

  //If the motion detector is triggering and the alarm is off, turn it on
  if (pirState == HIGH and alarmState == LOW){
    setAlarm("ON");
    alarmState = HIGH;
  }

  //If the sound sensor is triggering and the alarm is off, turn it on
  if(micState == HIGH and alarmState == LOW){
    setAlarm("ON");
    alarmState = HIGH;
  }

  //If the motion detector and sound sensor are not triggering and the alarm is on then turn the alarm off
  if(pirState == LOW and micState == LOW and alarmState == HIGH){
    setAlarm("OFF");
    alarmState = LOW;
  }
}
