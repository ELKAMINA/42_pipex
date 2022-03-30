#include "my_pipex.h"

int	parse_args(char *argument)
{
	if (argument[0] == '/')
		return (-1);
	else if	(ft_strchr(argument, '/') == 2)
		return (-2);
	else if (ft_strchr(argument, '.') != 0)
		return (-3);
	else	
		return (0);
}

char	*get_cmd(char *cd_op1)
{
	int 	ind;
	int		i;
	char	*cmd;

	i = 0;
	ind = ft_strrchr(cd_op1, '/');
	cmd = malloc(sizeof(char) * (ft_strlen(cd_op1) - ind));
	ind++;
	while(cd_op1[ind])
	{
		cmd[i] = cd_op1[ind];
		i++;
		ind++;
	}
	return (cmd);
}

void	test_paths(char	*paths[], char **cd_op, char *env[])
{
	int		i;
	char	*fi_cd;

	i = 0;
	while(paths[i])
	{
		fi_cd = ft_strjoin(paths[i], "/");
		fi_cd = ft_strjoin(fi_cd, cd_op[0]);
		if (access(fi_cd, F_OK) == 0)
		{
			if (execve(fi_cd, cd_op, env) == -1)
				perror("No such file or directory");
		}
		free(fi_cd);
		i++;
	}
}

int	exe_cmd(char **cd_op, char **paths, char *env[])
{
	if (parse_args(cd_op[0]) == -1 || parse_args(cd_op[0]) == -3)
	{
		if (access(cd_op[0], F_OK) == 0)
		{
			if (execve(cd_op[0], cd_op, env) == -1)
				perror("No such file or directory");
		}
	}
	else if (parse_args(cd_op[0]) == -2)
	{
		if (access(cd_op[0], F_OK) != 0)
			{
				perror(cd_op[0]);
				exit(1);
			}
	}
	else
		test_paths(paths, cd_op, env);
	return (EXIT_FAILURE);
}

void	p_child_one(int fd[], char *argv[], char **paths, char *env[])
{

	char	**cmd1_options;
	int		in;
	// int		i;

	// i = 0;
	in = open(argv[1], O_RDONLY | O_CREAT);
	if (in < 0)
		perror("Error:");
	close(fd[0]);
	cmd1_options = ft_split(argv[2], ' ');
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(in);
	exe_cmd(cmd1_options, paths, env);
}

void	p_child_two(int fd[], char *argv[], char **paths, char *env[])
{
	char	**cmd2_options;
	int		ou;

	waitpid(-1, NULL, 0);
	ou = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ou < 0)
		perror("Error:");
	cmd2_options = ft_split(argv[3], ' ');
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(ou, STDOUT_FILENO);
	close(ou);
	exe_cmd(cmd2_options, paths, env);
}

int	ft_my_pipex(char *argv[], char **paths, char *env[])
{
	int	fd[2];
	int	fi;
	int	sec;

	if (pipe(fd) == -1)
		return (errno);
	fi = fork();
	if (fi < 0) 
		return (errno);
	if (fi == 0)
		p_child_one(fd, argv, paths, env);
	sec = fork();
	if (sec < 0) 
		return (errno);
	if (sec == 0)
		p_child_two(fd, argv, paths, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(fi, NULL, 0);
	waitpid(sec, NULL, 0);
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

	if (argc != 5)
		exit (0);
	path = get_path(env);
	paths = ft_split(path, ':');
	free(path);
	ft_my_pipex(argv, paths, env);
	freeing(paths);
	return (0);
}
