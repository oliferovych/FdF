# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:54:36 by dolifero          #+#    #+#              #
#    Updated: 2024/05/11 19:19:16 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	FdF.c\
					parsing.c\
					error_checks.c\
					allocation_utilities.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= FdF

LIBFT_DIR 		= Libft
LIBFT			= $(LIBFT_DIR)/libft.a

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
BOLD_WHITE	=	\033[1;97m
BOLD_GREEN	=	\033[1;92m
NO_COLOR	=	\033[0m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[2;96m
WHITE		=	\033[0;97m

all:
				@echo "\n$(BOLD_CYAN)Starting $(BOLD_WHITE)[${NAME}] $(BOLD_CYAN)compilation..$(DEF_COLOR)\n"
				@Make ${NAME}
				@echo "\n$(BOLD_GREEN)${NAME} DONE!\n$(DEF_COLOR)"

clean:
				@echo "$(CYAN)"
				$(RM) $(OBJS) $(LIBFT_DIR)/*.o
				@echo "$(DEF_COLOR)"

fclean:
				@echo "$(CYAN)"
				$(RM) $(OBJS) $(NAME) $(LIBFT_DIR)/*.o $(LIBFT)
				@echo "$(DEF_COLOR)"

$(NAME):		$(OBJS) $(LIBFT)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

re:				fclean all

.PHONY:			all clean fclean re
