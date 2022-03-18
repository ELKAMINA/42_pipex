# Fork function 
Fork : it forks the execution line.
    When we get a fork, a child process gets born and start executing the following lines.
    It executes the main process in parallel
RETURN  VALUE FROM FORK : an int as 
Everything coming before fork function is executed once, but since fork, the process is duplicated (the main and the child process. The id for the child is always 0)

Wait function : tell to stop the execution until the child process is done.
it can be called only in the main process.
And it waits for one child process to finish only. When one of the children is done, wait terminate the main process

wait(NULL) returns -1 if there is nothing to wait for.

From the child process and the parent process, the argc and argv are the same.
but the place in the memory is not the same.

What is PIPE ?
doc : https://www.geeksforgeeks.org/pipe-system-call/
It makes us communicate between processes.
After its been forked, something to be sent over to aanother process.
in memory file. File that have a sort of buffer that is saved from memory
Its a function : int pipe(int fd[2]). It takes 2 files descriptors.
fd[0] == read
fd[1] == write
return -1 for error
Pour read and write, toujours checker pour les erreurs. ATTENTION !!!!!

When we fork, the fds are inside the system itself and are copied over the main process to the child process.
Pipes can be used only in processes with the same hierarchy.
Pipes behave FIFO(First in First out), Pipe behave like a queue data structure. Size of read and write don’t have to match here. We can write 512 bytes at a time but we can read only 1 byte at a time in a pipe.
