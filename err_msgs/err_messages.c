/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_messages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:53:09 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 16:53:13 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_pipex.h"

void	error_msgs(void)
{
	perror("Error ");
	exit(1);
}

int	pers_err_msges(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

int	cmd_not_found(char *error)
{
	write(2, error, ft_strlen(error));
	exit(127);
}
