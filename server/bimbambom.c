#include <unistd.h> // usleep

void turnOn()
{
  printf("ON\n");
}

void turnOff()
{
  printf("OFF\n");
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
