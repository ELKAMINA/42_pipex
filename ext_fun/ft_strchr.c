#include "../my_pipex.h"

int	ft_strchr(const char *s, int c)
{
	char			*sent;
	unsigned char	character;
	size_t			i;

	sent = (char *)s;
	character = (unsigned char)c;
	i = 1;
	// printf("character == %c\n", character);
	while (i <= ft_strlen(s))
	{
		if (sent[i] == character)
			return (2);
		i ++;
	}
	return (0);
}
