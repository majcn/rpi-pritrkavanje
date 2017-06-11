#include <stdio.h>  // printf
#include <unistd.h> // usleep

void turnOn()
{
  printf("BOM\n");
}

void turnOff()
{
}

int convertToMicroseconds(int bpm)
{
  return 60000000 / bpm;
}

void bimbambom(int *bpm_ptr)
{
  int delay = 1000;

  while(1)
  {
    turnOff();
    usleep(delay);
    turnOn();
    usleep(convertToMicroseconds(*bpm_ptr) - delay);
  }
}
