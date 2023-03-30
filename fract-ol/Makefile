# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 02:15:22 by trubat-d          #+#    #+#              #
#    Updated: 2022/10/31 16:37:32 by trubat-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/
SRC = complex.c fractal_compute.c fractal_main.c fractal_renderer.c key_event_handler.c util_handler.c arg_manager.c \
	ft_split.c ft_atoi.c ft_strlen.c ft_isdigit.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME	= fractol
AR 		= ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/ -Ilib/libmlx

OPTIONS = -L . -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de fractal_8bit...$(RESETTXT)"
		@gcc $(CFLAGS) $(INCLUDES) $(FRAMEWORKS) $(OPTIONS) $(OBJS) -o $@ 
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
		@$(RM) $(OBJS)
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de fractol...$(RESETTXT)"
		@$(RM) $(NAME)
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"
		
re:		fclean all

.PHONY: all clean fclean re 