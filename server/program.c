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
  bimbambom((int *)x_void_ptr);
}

int main(void)
{
  int bpm = 100;

  pthread_t magic_thread;
  if(pthread_create(&magic_thread, NULL, magic, &bpm)) {
    fprintf(stderr, "Error creating thread\n");
    return 1;
  }

  int sock, client, alen;
  struct sockaddr_rc addr;

  if( (sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM)) < 0)
    {
      perror("socket");
      exit(1);
    }

  addr.rc_family = AF_BLUETOOTH;
  bacpy(&addr.rc_bdaddr, BDADDR_ANY);
  addr.rc_channel = htobs(CHANNEL);
  alen = sizeof(addr);

  if(bind(sock, (struct sockaddr *)&addr, alen) < 0)
    {
      perror("bind");
      exit(1);
    }

  listen(sock,QUEUE);
  printf("Waiting for connections...\n\n");

  char buf[1024];
  while(client = accept(sock, (struct sockaddr *)&addr, &alen))
    {
      printf("Got a connection attempt!\n");
      int bytes_read = 1;
      while((bytes_read = read(client, buf, sizeof(buf))) > 0) {
        printf("%i", bytes_read);
        printf("received [%s]\n", buf);
        sscanf(buf, "%d", &bpm);
      }
      close(client);
    }

  close(sock);
  return 0;
}
