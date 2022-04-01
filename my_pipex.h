#ifndef my_pipex
# define my_pipex

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_my_pipex(char *argv[], char **paths, char *env[]);
void	freeing(char **paths);
int	    ft_strchr(const char *s, int c);
int	    ft_strrchr(const char *s, int c);
int     err_msges(char *error);
int     parse_args(char *argument);
char	*get_cmd(char *final_cmd, char *paths[]);
char	*test_paths(char *final_cmd, char	**paths);
int     exe_cmd(char **cd_op, char **paths, char *env[]);
void    p_child_one(int fd[], char *argv[], char **paths, char *env[]);
void    p_child_two(int fd[], char *argv[], char **paths, char *env[]);
int     ft_my_pipex(char *argv[], char **paths, char *env[]);
char    *get_path(char *env[]);
void    error_msgs();
int	    pers_err_msges(char *error);
int     cmd_not_found(char *error);

#endif
