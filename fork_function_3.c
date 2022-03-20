#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
/* ls -l | wc -l */
    int p[2];
    int pipe(int[2]);
    pipe(p);
    if (fork() == 0) {
        close(STDIN_FILENO);    /* fermer stdin */
        dup(p[0]);              /* stdin devient entrée tube */
        close(p[1]);
        close(p[0]);
        execl("/usr/ucb/wc", "wc", "-l", NULL);
    } else {
        close(STDOUT_FILENO);   /* fermer stdout */
        dup(p[1]);              /* stdout devient sortie tube */
        close(p[1]);
        close(p[0]);
        execl("/bin/ls", "ls", "-l", NULL);
    }
}