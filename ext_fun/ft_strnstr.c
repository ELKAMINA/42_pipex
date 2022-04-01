/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:55:46 by ael-khat          #+#    #+#             */
/*   Updated: 2022/04/01 17:55:50 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../my_pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hays;

	i = 0;
	j = 0;
	hays = (char *)haystack;
	if (needle[0] == '\0' || needle == NULL)
		return (hays);
	while (hays[i] != '\0' && i < len)
	{
		j = 0;
		while (hays[i] == needle[j] && hays != NULL
			&& needle[j] != '\0' && i < len)
		{
			i ++;
			j ++;
		}
		if (needle[j] == '\0' && i - j < len)
			return ((char *)hays + (i - j));
		i -= j;
		i++;
	}
	return (NULL);
}
