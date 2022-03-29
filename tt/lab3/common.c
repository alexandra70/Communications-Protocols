#include "common.h"

uint16_t inet_csum(uint8_t *buf, size_t len) {
	//TODO1: Calculate the internet checksum according to RFC1071

	/* Compute Internet Checksum for "count" bytes
	*         beginning at location "addr".
	*/
	uint32_t sum = 0;
	/* 
		Move through the buffer two bytes at the time,
		cast the bytes to a number and add them to the sum
	*/
	uint16_t checksum;
	int count = len;
	uint8_t* addr = buf;
	while( count > 1 )  {
		/*  This is the inner loop */
			sum += * (uint16_t *)addr;
			addr += 2;
			count -= 2;
	}
	
		/*  Add left-over byte, if any */
	if( count > 0 )
			sum += * (uint8_t *)addr;
	
		/*  Fold 32-bit sum to 16 bits */
	while (sum>>16)
		sum = (sum & 0xffff) + (sum >> 16);
	
	checksum = ~sum;

	return checksum;
	
}
