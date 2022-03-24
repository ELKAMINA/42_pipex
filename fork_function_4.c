#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"



void	get_cmd_exec(char *argv, char *env[])
{
	char	**argum;
	int		len;

	argum = ft_split(argv, " ");
	len = ft_strlen(
	get_env(env);
	get_path(argv

void	fst_child_pro(int infile, int outfile, int fd0, int fd1)
{
	int	cmd1;

	dup2(infile, STDIN_FILENO);
	dup2(fd0, STDOUT_FILENO);
	close(fd1);
	close(infile);
	execve( ,"ping", "5", "google.com", NULL);


void my_pipex(char *argv[], char *env[])
{
	int	fd[2];
	int	piping;
	int	cmd1;
	int	cmd2;
	//1. We're creating the pipe
	piping = pipe(fd);
	if (piping == -1)
		return ;
	//3. We're creating the fork
	int pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork"));
	if (pid1 == 0)
    {
		fst_child_pro(infile, outfile);
		get_cmd_exec(argv[2], env)
    // child process 1 (ping)
		//dup2(fd[1], STDOUT_FILENO);
	//	close(fd[0]);
	//	close(fd[1]);
	//	execlp("ping" ,"ping", "5", "google.com", NULL);
	}
	int pid2 = fork();
	if (pid2 < 0)
		return ;
	if (pid2 == 0)
	{
		//Child process 2 (grep)
		sgd_child_pro(infile, outfile);
	//	dup2(fd[0], STDIN_FILENO);
	//	close(fd[0]);
	//	close(fd[1]);
	//	execlp("grep", "grep", "round-trip", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *env[])
{
	int		infile;
	int		outfile;
//	char	*cmd1;
//	char	*cmd2;
//	char	*path1;
//	char	*path2;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_RDWR | O_CREAT, 0644);
	if (infile < 0 || outfile < 0)
		return (0);
//	cmd1 = ft_split(argv[1], " ");
//	cmd2 = ft_split(argv[4], " ");
	if (argc != 5)
		printf("Missing arguments");
    else
		my_pipex(infile, outfile, argv, env);
	return 0;
}
