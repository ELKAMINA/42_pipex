#include "my_pipex.h"

void	p_child_one(int fd[], char *argv[], char **paths, char *env[])
{

	char	**cmd1_options;
	int		in;

	in = open(argv[1], O_RDONLY);
	if (in < 0)
	{
		perror("Error ");
		exit(1);
	}
	close(fd[0]);
	cmd1_options = ft_split(argv[2], ' ');
	if (dup2(in, STDIN_FILENO) == -1)
		perror("Error :");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("Error :");
	close(in);
	exe_cmd(cmd1_options, paths, env);
}

void	p_child_two(int fd[], char *argv[], char **paths, char *env[])
{
	char	**cmd2_options;
	int		ou;

	waitpid(-1, NULL, 0);
	ou = open(argv[4], O_TRUNC | O_CREAT | O_RDWR , 0000644);
	if (ou < 0)
	{
		perror("Error ");
		exit(1);
	}
	cmd2_options = ft_split(argv[3], ' ');
	close(fd[1]);
	if	(dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Error ");
		exit(1);
	}
	if (dup2(ou, STDOUT_FILENO) == -1)
	{
		perror("Error ");
		exit(1);
	}
	close(ou);
	exe_cmd(cmd2_options, paths, env);
}

int	ft_my_pipex(char *argv[], char **paths, char *env[])
{
	int	fd[2];
	int	fi;
	int	sec;
	int	wstatus;

	if (pipe(fd) == -1)
		err_msges(ERR_PIPE);
	fi = fork();
	if (fi < 0) 
	{
		perror("Error ");
		exit(1);
	}
	if (fi == 0)
		p_child_one(fd, argv, paths, env);
	sec = fork();
	if (sec < 0) 
	{
		perror("Error ");
		exit(1);
	}
	if (sec == 0)
		p_child_two(fd, argv, paths, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(fi, NULL, 0);
	waitpid(sec, &wstatus, 0);
	if (WIFEXITED (wstatus))
		return (WEXITSTATUS(wstatus));
	return (0);
}

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
	char	*path;
	int ret;

	if (argc != 5)
		err_msges(ERR_INPUT);
	path = get_path(env);
	paths = ft_split(path, ':');
	free(path);
	ret = ft_my_pipex(argv, paths, env);
	freeing(paths);
	return (ret);
}
