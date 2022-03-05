#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    fork();
    fork();
    fork();
    fork();
    printf("Hello World \n");
    // if (id == 0)
    //     printf("Hello World from CHILD PROCESS\n");
    // else
    //     printf("Hello World from MAIN PROCESS\n");
    return (0);
}