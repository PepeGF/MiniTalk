SRCS_CLIENT = client.c ft_atoi.c ft_putnbr_fd.c ft_putchar_fd.c ft_strlen.c 

SRCS_SERVER = server.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

NAME_SERVER = server

NAME_CLIENT = client

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -f

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME_SERVER): $(OBJS_SERVER)
	@$(CC) -o $(NAME_SERVER) $?
	@echo "Server successfully compiled"

$(NAME_CLIENT): $(OBJS_CLIENT)
	@$(CC) -o $(NAME_CLIENT) $?
	@echo "Client successfully compiled"

clean:
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean $(NAME_SERVER) $(NAME_CLIENT)

.PHONY: all clean fclean re
