#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* pentru open(), exit() */
#include <fcntl.h> /* O_RDWR */
#include <errno.h> /* perror() */



//void fatal(char* mesaj_eroare)
//{
//    perror(mesaj_eroare);
//    exit(0);
//}


int main() {

    /*
    * cpy src -> dest
    * a file src have data, i want to transfer it to dest
    */

    int src = open("cat.txt", O_RDONLY);
    //third argument in case o_create is used is the setter of permissions for open

    if (src < 0) {
        perror("can't open file");
        exit(0); //return value;
    }

    lseek(src, 0, SEEK_SET); 
    char* buff = malloc(1024);

    int can_read;
    while ((can_read = read(src, buff, 1024))) {
        if (can_read < 0) {
            perror("something bad happened AT READING");
            exit(0);
        }
        //write directly at stdout -> write return -> - 1 in error case
	//and it returns the number of witten bytes in success case.
        can_read = write(STDOUT_FILENO, buff, can_read);
        if (can_read < 0) {
            perror("something bad happened AT WRITING");
            exit(0);
        }

    }
	
	close(src);
   	return 0;
}