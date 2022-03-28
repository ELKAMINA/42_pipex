#include "my_pipex.h"

void	exe_cmd(char *argv, char *env)
{
	char	**options;

	options = ft_split(argv[2]);


void	p_child(char *argv[], char *paths[], int in, int ou)
{
	char	**cmd1_options;
	int		i;

	i = 1;
	cmd1_options = ft_split(argv[2], " ");
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	// PROTEGER DUP2
	close(fd[0]);
	close(in);
	exe_cmd(argv[2], cmd1_options, paths);
}

void	my_pipex(char *argv[], char *paths[], int in, int ou)
{
	int	fd[2];
	int	fi;
	int	sec;

	if (pipe(fd) == -1)
		return (0);
	fi = fork();
	if (fi < 0) 
		return (perror("Fork");
	if (fi == 0)
		p_child(in, ou, argv, paths);
	else
		p_parent(in, ou, argv, paths);

char	*get_path(char *env[])
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while(env[i])
	{
		j = 0;
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			path = ft_substr(env[i], 5, (ft_strlen(env[i]) - 5));
			return(path);
		}
		while(env[i][j])
			j++;
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	char	**paths;
	int		infile;
	int		outfile;

	if (argc != 4)
		return (0);
	else
	{
		paths = ft_split(get_path(env), ":");
		infile = open(argv[1], O_RDONLY | O_CREAT);
		outfile = open(argv[4], O_RDWR | O_CREAT)
		if (infile < 0 | outfile < 0)
			return (0);
		my_pipex(argv, paths, infile, outfile);
	}
}
