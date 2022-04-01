/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pipex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:46:49 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 16:46:59 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_pipex.h"

int	parse_args(char *argument)
{
	if (argument[0] == '/')
		return (-1);
	else if (ft_strchr(argument, '/') == 2)
		return (-1);
	else if (ft_strchr(argument, '.') != 0)
		return (-1);
	else
		return (0);
}

char	*get_cmd(char *final_cmd, char *paths[])
{
	char	*fin_cd;

	if (parse_args(final_cmd) == -1)
	{
		if (access(final_cmd, F_OK) == 0)
			return (final_cmd);
	}
	else
	{
		fin_cd = test_paths(final_cmd, paths);
		return (fin_cd);
	}
	return (NULL);
}

char	*test_paths(char *final_cmd, char	*paths[])
{
	int		i;
	char	*fi_cd;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		fi_cd = ft_strjoin(tmp, final_cmd);
		free(tmp);
		if (access(fi_cd, F_OK) == 0)
			return (fi_cd);
		free(fi_cd);
		i++;
	}
	return (NULL);
}
