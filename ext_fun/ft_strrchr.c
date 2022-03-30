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
