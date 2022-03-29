#include "my_pipex.h"

int	exe_cmd(char **cd_op, char **paths)
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
			if (execve(fi_cd, cd_op, NULL) == -1)
				perror("exceve fail");
		}
		free(fi_cd);
		i++;
	}
	return (EXIT_FAILURE);
}

void	p_child_one(int fd[], char *argv[], char **paths)
{

	char	**cmd1_options;
	int		in;

	in = open(argv[1], O_RDONLY | O_CREAT);
	if (in < 0)
		perror("Error:");
	close(fd[0]);
	cmd1_options = ft_split(argv[2], ' ');
	dup2(in, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	// PROTEGER DUP2
	close(in);
	exe_cmd(cmd1_options, paths);
}

void	p_child_two(int fd[], char *argv[], char **paths)
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
	// PROTEGER DUP2
	close(ou);
	exe_cmd(cmd2_options, paths);
}

void	ft_my_pipex(char *argv[], char **paths)
{
	int	fd[2];
	int	fi;
	int	sec;
	if (pipe(fd) == -1)
		return ;
	fi = fork();
	if (fi < 0) 
	{
		perror("Fork");
		return ;
	}
	if (fi == 0)
		p_child_one(fd, argv, paths);
	sec = fork();
	if (sec < 0) 
	{
		perror("Fork");
		return ;
	}
	if (sec == 0)
		p_child_two(fd, argv, paths);
	close(fd[0]);
	close(fd[1]);
	waitpid(fi, NULL, 0);
	waitpid(sec, NULL, 0);
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

	if (argc < 5 || argc > 5)
		return (0);
	//printf("test\n");
	//printf("argv[0]: %s\n", argv[0]);
	paths = ft_split(get_path(env), ':');
	ft_my_pipex(argv, paths);
	return (0);
}
