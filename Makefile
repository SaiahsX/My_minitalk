#################################################################
####################--MINITALK MAKEFILE--########################
#################################################################

#################################################################
#				MY MANDATORY PART SOURCE FILES					#
#################################################################

SOURCES		=	server.c \
				client.c \

#################################################################
#					MY BONUS PART SOURCE FILES					#
#################################################################

BONUS_SOURCES	=	client_bonus.c \
					server_bonus.c \

#################################################################
#		MY MANDATORY PART C FILE COVERSION TO OBJECT .O FILES	#
#################################################################

OFILES		=	$(SOURCES:.c=.o)

#################################################################
#		MY BONUS PART C FILE COVERSION TO OBJECT .O FILES		#
#################################################################

BOFILES		=	$(BONUS_SOURCES:.c=.o)

#################################################################
#							ALIASES								#
#################################################################

CC			=	cc
RM			=	-rm -rf
CFLAGS		=	-Wall -Wextra -Werror -Ilibft

LIBFT 		=	libft/libft.a

# Color codes
RED            =   \033[0;31m
GREEN          =   \033[0;32m
YELLOW         =   \033[0;33m
BLUE           =   \033[0;34m
MAGENTA        =   \033[0;35m
CYAN           =   \033[0;36m
RESET          =   \033[0m

all:			server client client_bonus server_bonus

bonus:			client_bonus server_bonus

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	norminette $(SOURCES) $(BONUS_SOURCES)
	@echo "$(BLUE)norminette successful$(RESET)"
	
server: 		server.o $(LIBFT)
		@echo "$(GREEN)⛏🧱Building server files...$(RESET)"
		@ $(CC) $(CFLAGS) $^ -o $@
		@echo "$(BLUE)🤝server files built$(RESET)"

client:			client.o $(LIBFT)
		@echo "$(GREEN)⛏🧱Building client files...$(RESET)"
		@ $(CC) $(CFLAGS) $^ -o $@
		@echo "$(BLUE)🤝client files built$(RESET)"

client_bonus:			client_bonus.o $(LIBFT)
		@echo "$(GREEN)⛏🧱Building client_bonus files...$(RESET)"
		@ $(CC) $(CFLAGS) $^ -o $@
		@echo "$(BLUE)🤝client_bonus files built$(RESET)"

server_bonus: 		server_bonus.o $(LIBFT)
		@echo "$(GREEN)⛏🧱Building server_bonus files...$(RESET)"
		@ $(CC) $(CFLAGS) $^ -o $@
		@echo "$(BLUE)🤝server_bonus files built$(RESET)"

$(LIBFT):
	@echo "$(CYAN)⛏🧱Building libft...$(RESET)"
	@ make -C libft
	@echo "$(BLUE)🤝libft built$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@ $(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled - 🤩 CONGRATULATIONS 🤩! $(RESET)"

clean:
	@echo "$(RED)🧹Cleaning up...$(RESET)"
	@ make -C ./libft clean
	@ $(RM) $(OFILES) $(BOFILES)
	@echo "$(GREEN)✨all clean except executable files.$(RESET)"

fclean: clean
	@echo "$(RED)🧼🧽🧹Force cleaning...🧼🧽🧹$(RESET)"
	@ make -C libft fclean
	@ $(RM) server client $(OFILES)
	@ $(RM) client_bonus server_bonus $(BOFILES)
	@echo "$(GREEN)✨✨✨all object files & executable files cleaned.✨✨✨$(RESET)"

re: fclean all

bonus: client_bonus server_bonus

.PHONY: all clean fclean norm re bonus