CC = gcc -Wall -Wextra -Werror

NAME = pipex

SRC =	my_pipex.c\
			my_pipex2.c\
			./ext_fun/ft_strnstr.c\
			./ext_fun/ft_substr.c\
			./ext_fun/ft_strlen.c\
			./ext_fun/ft_strdup.c\
			./ext_fun/ft_calloc.c\
			./ext_fun/ft_bzero.c\
			./ext_fun/ft_split.c\
			./ext_fun/ft_strjoin.c\
			./ext_fun/ft_strchr.c\
			./ext_fun/ft_strrchr.c\
			./freeing/freeing.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
