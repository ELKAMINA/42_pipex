#ifndef my_pipex
# define my_pipex

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_my_pipex(char *argv[], char **paths);
void	freeing(char **paths);


#endif
