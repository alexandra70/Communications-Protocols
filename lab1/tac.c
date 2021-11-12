#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> /* pentru open(), exit() */
#include <fcntl.h> /* O_RDWR */
#include <errno.h> /* perror() */

int main(int argc, char* argv[]) {


    int src = open(argv[1], O_RDONLY);
    //third argument in case o_create is used is the setter of permissions for open

    FILE* fp = fopen(argv[1], "r");

    if (src < 0) {
        perror("can't open file");
        exit(0); //return value;
    }

    lseek(src, 0, SEEK_SET);
    char* buff = malloc(1024);
    char* t = malloc(1024);

    int can_read;

    char** tac = malloc(100 * sizeof(char*));
    char* reverse = malloc(1024 * sizeof(char));
    char* all = malloc(sizeof(buff));

    can_read = read(src, buff, 1024);
    if (can_read < 0) {
        perror("something bad happened AT READING");
        exit(0);
    }

    //range of line index - where do i find the beggining of line

   
    all = strtok(buff, "\n");
  
    int line = 0;
    tac[line] = all;
    while (all) {
        tac[line] = all;
        all = strtok(NULL, "\n");
        line++;
    }

    //print at output
    int j = 0;
    for (int i = line -1; i >= 0; i--) {
        strcat(reverse, tac[i]);
        strcat(reverse, "\n");
    }
    printf("%s\n", reverse);
    can_read = write(STDOUT_FILENO, reverse, can_read);

    free(buff);
    free(reverse);
  
    close(src);

    return 0;
}