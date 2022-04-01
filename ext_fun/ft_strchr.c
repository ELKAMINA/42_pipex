/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:54:29 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 17:54:31 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_pipex.h"

int	ft_strchr(const char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 1;
	while (i <= ft_strlen(s))
	{
		if (sent[i] == character)
			return (2);
		i ++;
	}
	return (0);
}
