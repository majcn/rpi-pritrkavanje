#include "bimbambom.h"

#include <stdio.h>  // printf
#include <wiringPi.h>

void turnOn()
{
  digitalWrite(0, HIGH);
}

void turnOff()
{
  digitalWrite(0, LOW);
}

int convertToMiliseconds(int bpm)
{
  return 60000 / bpm;
}

void bimbambom(Song *song)
{
  wiringPiSetup();
  pinMode(0, OUTPUT);

  int delayMiliseconds = 100;

  while(1)
  {
    turnOff();
    delay(delayMiliseconds);
    turnOn();
    delay(convertToMiliseconds(song->bpm) - delayMiliseconds);
  }
}
