# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:54:36 by dolifero          #+#    #+#              #
#    Updated: 2024/12/13 15:29:18 by dolifero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= FdF

SRCS			=	FdF.c\
					parsing.c\
					errors.c\
					allocation_utilities.c\
					controls.c\
					image_calc.c\
					overlay.c\
					draw.c\
					math_utils.c\
					brezenham.c
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
BR_CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

all:			$(NAME) visual_init

libmlx:
				mkdir -p $(LIBMLX)/build
				cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
				@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERLIBMLX)

$(NAME):		$(MAKELIBMLX) $(OBJS) $(LIBFT)
				@$(CC) $(OBJS) -Llibft -LMLX42 -lft $(LIBS) $(HEADERS) -o $(NAME) > /dev/null 2>&1

$(LIBFT):
				@echo "\n$(BOLD_CYAN)Starting $(BOLD_WHITE)[${LIBFT}] $(BOLD_CYAN)compilation..$(DEF_COLOR) $(CYAN)"
				$(MAKE) -C $(LIBFT_DIR)

$(MAKELIBMLX):	$(LIBMLX)
				@echo "\n$(DEF_COLOR)$(BOLD_CYAN)Starting $(BOLD_WHITE)[${LIBMLX}] $(BOLD_CYAN)compilation..$(DEF_COLOR)$(CYAN)"
				@mkdir -p $(LIBMLX)/build
				@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
				tput cup 10 0 && tput ed
				@echo "\n$(BOLD_GREEN)${LIBMLX} DONE!\n$(DEF_COLOR)"

$(LIBMLX):
				@echo "\n$(BOLD_CYAN)Cloning $(BOLD_WHITE)[${LIBMLX}] $(BOLD_CYAN)library..$(DEF_COLOR)$(CYAN)"
				touch .gitmodules
				git submodule add -f https://github.com/codam-coding-college/MLX42.git

clean:
				@echo "$(CYAN)"
				$(RM) $(OBJS) $(LIBFT_DIR)/*.o
				$(RM) -rf $(LIBMLX)/build
				@echo "$(BOLD_GREEN)Clean!\n$(DEF_COLOR)"

fclean:
				@echo "$(CYAN)"
				$(RM) -rf $(OBJS) $(NAME) $(LIBFT_DIR)/*.o $(LIBFT)
				@echo "$(DEF_COLOR)$(BOLD_GREEN)Fclean!\n$(DEF_COLOR)"

lclean:
				@echo "$(CYAN)"
				$(RM) -rf $(LIBMLX)
				@echo "$(DEF_COLOR)$(BOLD_GREEN)Library cleaned!\n$(DEF_COLOR)"

re:				fclean lclean all

visual_init:	clear
				@$(MAKE) FDF_CYAN
				@echo "$(BR_CYAN)"
				@$(MAKE) loading
				@echo "$(DEF_COLOR)"
				clear
				@$(MAKE) FDF_GREEN
				@echo "$(GREEN)    DONE!    \n   ███████████████████████████████████████████$(DEF_COLOR)\n"

clear:
				@clear

FDF_CYAN:
				@echo "\n$(BR_CYAN)             ███████╗██████╗ ███████╗"
				@echo "             ██╔════╝██╔══██╗██╔════╝"
				@echo "             █████╗  ██║  ██║█████╗  "
				@echo "             ██╔══╝  ██║  ██║██╔══╝  "
				@echo "             ██║     ██████╔╝██║     "
				@echo "             ╚═╝     ╚═════╝ ╚═╝     $(DEF_COLOR)\n"



FDF_GREEN:
				@echo "\n$(GREEN)             ███████╗██████╗ ███████╗"
				@echo "             ██╔════╝██╔══██╗██╔════╝"
				@echo "             █████╗  ██║  ██║█████╗  "
				@echo "             ██╔══╝  ██║  ██║██╔══╝  "
				@echo "             ██║     ██████╔╝██║     "
				@echo "             ╚═╝     ╚═════╝ ╚═╝     $(DEF_COLOR)\n"

loading:
				@printf "   "
				@for i in {1..43}; do \
					printf '%s' "█"; \
					sleep 0.01; \
				done

.PHONY:			all clean fclean lclean re libmlx

