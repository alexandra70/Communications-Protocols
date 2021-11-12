#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001

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


int main(void)
{
	msg r;
	int i, res;
	
	printf("[RECEIVER] Starting.\n");
	init(HOST, PORT);
	int par = 0;
	int correct = 0;
	
	for (i = 0; i < COUNT; i++) {
		/* wait for message */
		res = recv_message(&r);
		if (res < 0) {
			perror("[RECEIVER] Receive error. Exiting.\n");
			return -1;
		}

		par = 0;
		for (int j = 0; j < r.len; j++) {
			par += byteParity(r.payload[j]); //sau tot cu xor
		}
		if (par == r.par) {
			correct++;
		}

		printf("%s %s\n", "Message was Received: ", r.payload);
		/* send dummy ACK */
		res = send_message(&r);
		if (res < 0) {
			perror("[RECEIVER] Send ACK error. Exiting.\n");
			return -1;
		}
	}

	printf("[RECEIVER] Finished receiving..\n");

	printf(" %d \n", correct);

	return 0;
}
