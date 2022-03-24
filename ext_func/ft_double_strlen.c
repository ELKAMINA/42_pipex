#include "../pipex.h"

int	ft_double_strlen(const char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
			j++;
		i++;
	}
	return (i);
}
