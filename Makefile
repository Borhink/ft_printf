# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 16:05:27 by qhonore           #+#    #+#              #
#    Updated: 2016/09/23 05:02:49 by qhonore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIB_PATH = ./lib/

SRC_NAME = ft_printf.c print_str.c print_utf.c valid_type.c \
		   print_int.c print_uint.c utils.c utils_utf.c \
		   print_base.c parser.c print_arg.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
NAME = libftprintf.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	libtool -static -o $@ $^ $(LIB_PATH)libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB_PATH)libft/
	@cp $(LIB_PATH)libft/libft.a $(LIB_PATH)

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@echo "\033[37;44m Fclean libft \033[0m"
	@make -C $(LIB_PATH)libft/ fclean
	@rm -f $(LIB_PATH)/libft.a
	@echo "\033[37;44m Fclean $(NAME) \033[0m"
	rm -f $(NAME)

re: fclean all
