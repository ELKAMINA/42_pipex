#include "my_pipex.h"

void	my_pipex(char *argv[], char **paths)
{
	int	fd[2];
	int	fi;
	int	sec;
/*
	if (pipe(fd) == -1)
		return ;
	fi = fork();
	if (fi < 0) 
	{
		perror("Fork")
		return ;
	}
	if (fi == 0)
		p_child_one(fd, argv, paths);
	sec = fork();
	if (sec < 0) 
	{
		perror("Fork")
		return ;
	}
	if (sec == 0)
		p_child_two(fd, argv, paths);
	close(end[0]);
	close(end[1]);
	waitpid(fi, &status, 0);
	waitpid(sec, &status, 0);
	*/
}

