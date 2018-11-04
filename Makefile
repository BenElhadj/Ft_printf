# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 01:54:04 by bhamdi            #+#    #+#              #
#    Updated: 2018/11/04 07:50:09 by bhamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS = -g3 -Werror -Wall -Wextra -flto -O3 #-fsanitize=address	\
#		 -fno-omit-frame-pointer		\
#		 -fsanitize-address-use-after-scope \


SRCS_DIR = srcs/
OBJ_DIR = obj/

SRC = ft_flag.c ft_option.c ft_printf.c ft_specifier1.c ft_specifier2.c \
	  ft_fonction.c ft_fonction1.c ft_fonction2.c ft_filling.c ft_w_to_char.c\
	  ft_wchar_c.c ft_filling.c 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all : $(NAME)

$(NAME): $(OBJ)
	
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	
	@echo "\t\033[1;44mIt's finish\033[0;32m\t\t\t[ √ ]\033[0m\n\n"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I includes -c $< -o $@
	
	@echo "\033[1;34m$(addprefix)\t\033[1;33mCompilation\t\t\t\033[0;32m[OK]\033[0m"

.PHONY: clean fclean

clean:
	
#	@make -C $(OBJ) clean		
	@rm -rf $(OBJ)
	
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCleaning\tclean OBJ\t\033[0;32m[OK]\033[0m"


fclean: clean
	
#	@make -C $(OBJ) fclean		
	@rm -rf $(NAME)
	
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCleaning\t$(NAME)\t\033[0;32m[OK]\033[0m"

re: fclean all
