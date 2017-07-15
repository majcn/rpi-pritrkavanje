#include "bimbambom.h"

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <pthread.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#define CHANNEL 1
#define QUEUE 1

void *magic(void *x_void_ptr) {
  bimbambom((struct Song *)x_void_ptr);
}

int main(void)
{
  struct Song song;
  song.bpm = 100;

  pthread_t magic_thread;
  pthread_create(&magic_thread, NULL, magic, &song);

  struct sockaddr_rc addr;
  addr.rc_family = AF_BLUETOOTH;
  bacpy(&addr.rc_bdaddr, BDADDR_ANY);
  addr.rc_channel = htobs(CHANNEL);

  int sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM));
  int alen = sizeof(addr);
  bind(sock, (struct sockaddr *)&addr, alen);
  listen(sock, QUEUE);

  char buf[1024];
  int client, bytes_read;
  while(client = accept(sock, (struct sockaddr *)&addr, &alen))
  {
    while((bytes_read = read(client, buf, sizeof(buf))) > 0)
    {
      song.bpm = atoi(buf);
    }
    close(client);
  }

  close(sock);
  return 0;
}
