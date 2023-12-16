NAME = pipex

INCLUDE = -I includes/

DIR = ./srcs/

SRC = ft_find_cmd_in_env.c \
      ft_perform_checks.c \
      ft_process_handler.c \
      main.c

FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)

OBJS = $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: $(DIR)%.c
	$(CC) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all