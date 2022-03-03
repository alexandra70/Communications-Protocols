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

int main() {

    int fd_src = open("exercitiul_4", O_RDONLY);
    
    int copiat;
    char buf[100];
    while ((copiat = read(fd_src, buf, 100))) {
        if (copiat < 0)
            fatal("Eroare la citire");
        
        write(1, buf, copiat);
    }

    return 0;
}