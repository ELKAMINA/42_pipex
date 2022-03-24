#ifndef PIPEX_H
# define PIPEX_H

static int	count_words(char const *s, char c);
static int	is_mychar(char c, char s);
static char	*to_malloc(char const *str, char c);
static char	**ft_malloc_error(char **tab, int j);
char	**ft_split(char const *s, char c);
int	ft_double_strlen(const char *str);

#endif