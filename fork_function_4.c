#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "ft_printf/ft_printf.h"

void my_pipex(int f1, int f2)
{
    int fd[2];
        int piping;

        //1. We're creating the pipe
        piping = pipe(fd);
        // 2. Protecting our pipe.
        if (piping == -1)
            return 1;
        //2. We're creating the fork
        int pid1 = fork();
        if (pid1 < 0)
            return (perror("Fork"));
        ft_printf("%s\n", argv[2]);
        if (pid1 == 0)
        {
            // child process 1 (ping)
            dup2(fd[1], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execlp(argv[2], argv[2], "5", "google.com", NULL);
        }
        int pid2 = fork();
        if (pid2 < 0)
            return 3;
        if (pid2 == 0)
        {
            //Child process 2 (grep)
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            close(fd[1]);
            execlp("grep", "grep", "round-trip", NULL);
        }
        close(fd[0]);
        close(fd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
}

int main(int argc, char *argv[])
{
    if (argc != 5)
        ft_printf("Missing arguments");
    else
    {
        my_pipex()
    return 0;
    
}