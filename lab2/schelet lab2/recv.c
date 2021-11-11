#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "link_emulator/lib.h"

#define HOST "127.0.0.1"
#define PORT 10001


int main(int argc,char** argv){
  msg r;
  init(HOST,PORT);

  if (recv_message(&r)<0){
    perror("Receive message");
    return -1;
  }

  int len_file = r.len;
  printf("you can start to send...\n");

  strcat(r.payload, ".out");
  int out_desc = open(r.payload, O_WRONLY | O_TRUNC | O_CREAT, 0777);

  sprintf(r.payload, "%s", "ACK");
  r.len = strlen(r.payload);
  send_message(&r);


  memset(r.payload, 0 , MAX_LEN);
  while (len_file >= 0) {
    //cat timp primesc procesez mesajul
    if(recv_message(&r) < 0) {
      break;
    }
    len_file -= r.len;

    if(r.len != strlen(r.payload)) {
      printf("corupt\n");
      break;
    }

    if(write(out_desc, r.payload, r.len) < 0) {
      break;
    }

    printf("recv\n");
    memset(r.payload, 0 , MAX_LEN);
    sprintf(r.payload, "%s", "ACK");
    r.len = strlen(r.payload);
    send_message(&r);

    //clean-up again
    memset(r.payload, 0 , MAX_LEN);
  }

  close(out_desc);

  return 0;
}
