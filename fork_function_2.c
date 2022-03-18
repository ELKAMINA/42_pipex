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
    (void)argc;
    (void)argv;
    // int fd[2];
    // if (pipe(fd) == -1)
    //     return (1);
    //mkfifo("myfifo", 0777);
    if (mkfifo("myfifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("could not create fifo file\n");
            return (1);
        }
    }
    printf("Opening..\n");
    int fd = open("myfifo", O_WRONLY);
    printf("Opened\n");
    int x = 97;
    if  (write(fd, &x, sizeof(x)) == -1)
        return (2);
    printf("Written");
    close(fd);
    printf("Closed\n");
    return (0);

}