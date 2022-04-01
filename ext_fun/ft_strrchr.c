/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:56:13 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 17:56:15 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_pipex.h"

int	ft_strrchr(const char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;
	int				j;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 0;
	j = -1;
	while (i <= ft_strlen(s))
	{
		if (sent[i] != character)
			i++;
		else
		{
			j = i;
			i++;
		}
	}
	if (j == -1)
		return (0);
	return (j);
}
