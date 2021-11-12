#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10000
//func in care verific dc un mesaj un anumit byte drintr un mesaj mai mare
//are un numar par sau nu de biti setati, dupa care aceasta suma se
//adauga la suma per total, per mesaj, la fel xorata si ea.
int byteParity(unsigned char myChar) {
	int res = 0;

	//each bit in my char verify it
	for (int i = 0; i < 8; i++) {
		if (myChar & (1 << i)) {
			res = res ^ 1; //reset it if it was 1, else set it.
		}
	}
	return res;
}

int main(int argc, char* argv[])
{
	msg t;
	int i, res;

	printf("[SENDER] Starting.\n");
	init(HOST, PORT);

	int W = 10;
	int par = 0;

	for (int i = 0; i < W; i++) {
		memset(t.payload, 0, MSGSIZE);
		strncpy(t.payload, "package", strlen("package") + 1);
		t.par = 0;
		t.len = strlen("package") + 1;

		par = 0;
		for (int j = 0; j < t.len; j++) {
			par += byteParity(t.payload[j]); //sau tot cu xor
		}
		t.par = par;
		if (send_message(&t) < 0) {
			perror("[SENDER] Send error. Exiting.\n");
			return -1;
		}
		//printf("%s %s\n", "Message was sent: ", t.payload);
	}

	for (i = 0; i < COUNT - W; i++) {
		/* cleanup msg */
		memset(&t, 0, sizeof(msg));

		/* gonna send an not empty msg */
		strncpy(t.payload, "package", strlen("package") + 1);
		t.len = strlen("package") + 1;

		par = 0;
		for (int j = 0; j < t.len; j++) {
			par += byteParity(t.payload[j]); //sau tot cu xor
		}
		t.par = par;

		
		/* send msg */
		res = send_message(&t);
		if (res < 0) {
			perror("[SENDER] Send error. Exiting.\n");
			return -1;
		}
		//printf("%s %s\n", "Message was sent: ", t.payload);
		/* wait for ACK */
		res = recv_message(&t);
		if (res < 0) {
			perror("[SENDER] Receive error. Exiting.\n");
			return -1;
		}
	}

	for (i = 0; i < W; i++) {
		res = recv_message(&t);
		if (res < 0) {
			perror("[SENDER] Receive error. Exiting.\n");
			return -1;
		}
		printf("%s\n", "Message was received.");
	}


	printf("[SENDER] Job done, all sent.\n");

	return 0;
}
