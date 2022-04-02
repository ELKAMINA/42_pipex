/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:40:53 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/02 15:57:53 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_pipex.h"

void	p_child_one(int fd[], char *argv[], char **paths, char *env[])
{
	char	**cmd1_options;
	int		in;
	char	*final_cmd;

	in = open(argv[1], O_RDONLY);
	if (in < 0)
	{
		freeing(paths);
		error_msgs();
	}
	close(fd[0]);
	cmd1_options = ft_split(argv[2], ' ');
	final_cmd = get_cmd(cmd1_options[0], paths);
	if (final_cmd == NULL)
		freeing_cmd(paths, final_cmd, cmd1_options);
	if (dup2(in, STDIN_FILENO) == -1)
		perror("Error :");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("Error :");
	close(in);
	if (execve(final_cmd, cmd1_options, env) == -1)
		freeing_execution(paths, final_cmd, cmd1_options);
}

void	p_child_two(int fd[], char *argv[], char **paths, char *env[])
{
	char	**cmd2_options;
	char	*final_cmd;
	int		ou;

	ou = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (ou < 0)
	{
		freeing(paths);
		error_msgs();
	}
	cmd2_options = ft_split(argv[3], ' ');
	final_cmd = get_cmd(cmd2_options[0], paths);
	if (!final_cmd)
		freeing_cmd(paths, final_cmd, cmd2_options);
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_msgs();
	if (dup2(ou, STDOUT_FILENO) == -1)
		error_msgs();
	close(ou);
	if (execve(final_cmd, cmd2_options, env) == -1)
		freeing_execution(paths, final_cmd, cmd2_options);
}

int	ft_my_pipex(char *argv[], char **paths, char *env[])
{
	int	fd[2];
	int	fi;
	int	sec;
	int	wstatus;

	if (pipe(fd) == -1)
		pers_err_msges(ERR_PIPE);
	fi = fork();
	if (fi < 0)
		error_msgs();
	if (fi == 0)
		p_child_one(fd, argv, paths, env);
	sec = fork();
	if (sec < 0)
		error_msgs();
	if (sec == 0)
		p_child_two(fd, argv, paths, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(fi, &wstatus, 0);
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
	while (env[i])
	{
		j = 0;
		if (ft_strnstr(env[i], "PATH=", 5) != NULL)
		{
			path = ft_substr(env[i], 5, (ft_strlen(env[i]) - 5));
			return (path);
		}
		while (env[i][j])
			j++;
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *env[])
{
	char	**paths;
	char	*path;
	int		ret;

	if (argc != 5)
		pers_err_msges(ERR_INPUT);
	path = get_path(env);
	paths = ft_split(path, ':');
	if (!paths[0])
		freeing(paths);
	free(path);
	ret = ft_my_pipex(argv, paths, env);
	freeing(paths);
	return (ret);
}
