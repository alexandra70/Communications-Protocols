#include <unistd.h> /* pentru open(), exit() */
#include <fcntl.h> /* O_RDWR */
#include <stdio.h> /* perror() */
#include <errno.h>
#include <stdlib.h>
#include <string.h>
 
void fatal(char * mesaj_eroare)
{
    perror(mesaj_eroare);
    exit(0);
}
#define LEN 50

struct Packet {
    char  payload[100];
    int   sum;
    int   size;
};  

int main() {
    struct Packet pck;
    int fd_src = open("ex3.txt", O_RDONLY);
    int fdout = open("destinatie", O_WRONLY | O_CREAT, 0644);

    int copiat;
    
    while ((copiat = read(fd_src, &pck, 108))) {
        if (copiat < 0)
            fatal("Eroare la citire");
        
        printf("Payload: %s, ", pck.payload);
        printf("sum: %d, ", pck.sum);
        printf("size: %d\n", pck.size);
        memset(&pck, 0, 108);
    }

    return 0;
}