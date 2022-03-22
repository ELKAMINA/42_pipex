#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd[2];
    //1. We're creating the pipe
    if (pipe(fd) == -1)
        return 1;
    //2. We're creating the fork
    int pid1 = fork();
    if (pid1 < 0)
        return 2;
    if (pid1 == 0)
    {
        // child process 1 (ping)
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "5", "google.com", NULL);
    }
    int pid2 = fork();
    if (pid2 < 0)
        return 3;
    if (pid2 == 0)
    {
        //Child process 2 (grep)
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        execlp("grep", "grep", "rtt", NULL);
    }
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
    
}