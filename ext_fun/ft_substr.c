/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:54:07 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 16:54:18 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_pipex.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;
	size_t	tmp;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) + 1 < len)
		tmp = ft_strlen(s);
	else
		tmp = len;
	copy = (char *)ft_calloc((tmp + 1), sizeof (char));
	if (copy == NULL)
		return (NULL);
	while (s[i] && i < tmp)
	{
		copy[i] = s[start + i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}
