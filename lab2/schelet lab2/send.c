#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "link_emulator/lib.h"

#define HOST "127.0.0.1"
#define PORT 10000


int main(int argc,char** argv){
  init(HOST,PORT);
  msg t;

  memset(t.payload, 0, MAX_LEN);
  sprintf(t.payload, "%s", "in");

  int fin_des = open("in", O_RDONLY);
  int len_file = lseek(fin_des, 0, SEEK_END);

  lseek(fin_des, 0 , SEEK_SET);//ma repozitionez la inceput.
  t.len = len_file; //pun in lungimea mesajului lungimea input file.
  
  send_message(&t);
  if(recv_message(&t) < 0) {
    printf("nu primesc ack");
    return -1;
  }

  printf("len_fiel%d\n", len_file);
  int r_bytes;
  while (len_file > 0) { //la 0 sunt la sf fisierului.

    memset(t.payload, 0, MAX_LEN);
    if((r_bytes = read(fin_des, t.payload, MAX_LEN)) < 0) {
      printf("lungimea - > %d\n", r_bytes);
      return -1;
    }
    len_file -= r_bytes;
    t.len = strlen(t.payload);

    send_message(&t);

    if(recv_message(&t) < 0) {
      return -1;
    }
    printf("eu tirmit ceva\n");
    printf("len_fiel%d\n", len_file);

  }

  close(fin_des);
  return 0;
}
