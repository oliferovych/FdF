# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:54:36 by dolifero          #+#    #+#              #
#    Updated: 2024/05/14 16:39:58 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= FdF

SRCS			=	FdF.c\
					parsing.c\
					error_checks.c\
					allocation_utilities.c\
					controls.c
OBJS			= ${SRCS:.c=.o}

HEADERLIBMLX	= -I $(LIBMLX)/include/MLX42

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

LIBFT_DIR 		= ./Libft
LIBFT			= $(LIBFT_DIR)/libft.a
LIBS			= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBMLX			= ./MLX42
MAKELIBMLX		= ./MLX42/build/libmlx42.a

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
				@Make $(NAME)
				@echo "\n$(BOLD_GREEN)${NAME} DONE!\n$(DEF_COLOR)"

libmlx:
				mkdir -p $(LIBMLX)/build
				cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
				$(CC) $(CFLAGS) -o $@ -c $< $(HEADERLIBMLX)

$(NAME):		$(OBJS) $(LIBFT) $(MAKELIBMLX)
				$(CC) $(OBJS) -Llibft -LMLX42 -lft $(LIBS) $(HEADERS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR)

$(MAKELIBMLX):	$(LIBMLX)
				@echo "\n$(BOLD_CYAN)Starting $(BOLD_WHITE)[${LIBMLX}] $(BOLD_CYAN)compilation..$(DEF_COLOR)\n"
				@mkdir -p $(LIBMLX)/build
				@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
				@echo "\n$(BOLD_GREEN)${LIBMLX} DONE!\n$(DEF_COLOR)"

$(LIBMLX):
				touch .gitmodules
				git submodule add -f https://github.com/codam-coding-college/LIBMLX42.git

clean:
				@echo "$(CYAN)"
				$(RM) $(OBJS) $(LIBFT_DIR)/*.o
				$(RM) -rf $(LIBMLX)/build
				@echo "$(DEF_COLOR)"
				@echo "\n$(BOLD_GREEN)Clean!\n$(DEF_COLOR)"

fclean:
				@echo "$(CYAN)"
				$(RM) -rf $(OBJS) $(NAME) $(LIBFT_DIR)/*.o $(LIBFT)
				$(RM) -rf $(LIBMLX)/build
				@echo "$(DEF_COLOR)"
				@echo "\n$(BOLD_GREEN)Fclean!\n$(DEF_COLOR)"

re:				fclean all

.PHONY:			all clean fclean re libmlx

