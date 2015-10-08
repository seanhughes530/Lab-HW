#include <RFduinoGZLL.h>
#include "pitches.h"
#define NO_SOUND 0

device_t role = HOST;
char state = 0;
int LEDpin = 4;
int LEDpin2 = 2;

int music[] = {
  NOTE_AS7, 5000
};

//int musicOff = MUSIC_STOP;
int spkrPin = 6;


void setup()
{
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  
  // start the GZLL stack
  RFduinoGZLL.begin(role);
}

void loop()
{
  //  digitalWrite(LEDpin,HIGH);

}

void on() {
  digitalWrite(LEDpin, HIGH);
  digitalWrite(LEDpin2,HIGH);
}
void off() {
  digitalWrite(LEDpin, LOW);
  digitalWrite(LEDpin2, LOW);
}

void playMusic() {
  for (int Note = 0; Note < 7; Note++) {
    int duration = 1;
    tone(spkrPin, music[Note], duration);
  }
}



void RFduinoGZLL_onReceive(device_t device, int rssi, char *data, int len)
{
  Serial.println(data);

  if (data[0] == '1') {
    digitalWrite(LEDpin, HIGH);
  } else if (data[0] == '0') {
    digitalWrite(LEDpin, LOW);
  } 

  if (data[0] == '2') {
    digitalWrite(LEDpin2, LOW);
    
  } else if (data[0] == '3') {
    digitalWrite(LEDpin2, HIGH);
    playMusic();
  }
 }

