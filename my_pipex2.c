#include "my_pipex.h"

int	err_msges(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

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
			execve(fi_cd, cd_op, env);
		free(fi_cd);
		i++;
	}
	dprintf(2, "command not found\n");
	exit(127);
}

int	exe_cmd(char **cd_op, char **paths, char *env[])
{
	if (parse_args(cd_op[0]) == -1 || parse_args(cd_op[0]) == -3)
	{
		if (access(cd_op[0], F_OK) == 0)
			execve(cd_op[0], cd_op, env);
		else
		{
			perror(NULL);
			exit(127);
		}
	}
	else if (parse_args(cd_op[0]) == -2)
	{
		if (access(cd_op[0], F_OK) != 0)
			err_msges(ERR_CMD);
	}
	else
		test_paths(paths, cd_op, env);
	return (0);
}