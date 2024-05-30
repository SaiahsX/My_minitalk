SOURCES		=	server.c \
				client.c \

BONUS_SOURCES	=	client_bonus.c \
					server_bonus.c \

OFILES		=	$(SOURCES:.c=.o)
CC			=	cc
RM			=	-rm -rf
CFLAGS		=	-Wall -Wextra -Werror -Ilibft

LIBFT 		=	libft/libft.a

all:			server client $(LIBFT)

server: 		server.o $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

client:			client.o $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

norm:
	norminette $(SOURCES)

$(LIBFT):
	make -C libft

client_bonus:			client_bonus.o $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

server_bonus: 		server_bonus.o $(LIBFT)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft
	$(RM) $(OFILES) client_bonus.o server_bonus.o

fclean: clean
	make fclean -C libft
	$(RM) server client $(OFILES)
	$(RM) client_bonus server_bonus

re: fclean all

bonus: client_bonus server_bonus

.PHONY: all clean fclean norm re bonus