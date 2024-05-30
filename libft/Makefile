SRCS     =   ft_atoi.c \
             ft_bzero.c \
             ft_calloc.c \
             ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_putstr_fd.c \
            ft_strtrim.c \
            ft_split.c \
            ft_strchr.c \
            ft_strdup.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_putnbr_fd.c \
            ft_putchar_fd.c \
            ft_strjoin.c \
            ft_strlen.c \
            ft_strncmp.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_tolower.c \
            ft_toupper.c \
            ft_putendl_fd.c \
            ft_substr.c \
            ft_itoa.c \
            ft_strmapi.c \
            ft_striteri.c \
            ft_printf.c \
			print_hexadecimal.c \
			print_str_fd.c \
			print_nbr_fd.c \
			print_char_fd.c \
			print_pointer_hex.c \
			print_unsign_fd.c

BONUS_SRCS  =   ft_lstnew_bonus.c \
                ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
                ft_lstclear_bonus.c \
                ft_lstiter_bonus.c \
                ft_lstmap_bonus.c \

OFILES    =    $(SRCS:.c=.o)

BOFILES   =    $(BONUS_SRCS:.c=.o)

CC        =    cc
RM        =    -rm -rf
CFLAGS    =    -Wall -Wextra -Werror

NAME    =    libft.a

all:        $(NAME)

$(NAME):    $(OFILES)
		ar -rcs $(NAME) $(OFILES)

BONUS = .bonus

bonus:  ${BONUS}

${BONUS}:   $(OFILES) $(BOFILES)
		ar -rcs $(NAME)  $(OFILES) $(BOFILES)
		touch ${BONUS}

${BOFILES}:     ${BONUS_SRCS}
		cc	${CFLAGS}	-c ${BONUS_SRCS}	-I	libft.h

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OFILES) $(BOFILES) $(BONUS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re