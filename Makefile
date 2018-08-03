# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 05:26:55 by bhamdi            #+#    #+#              #
#    Updated: 2018/08/02 23:42:11 by bhamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Off=\033[0m             # Color off

BRed=\033[0;31m         # Red
BGreen=\033[1;32m       # Green
BWhite=\033[1;37m       # White

AWK = awk '{print $$1, $$2, $$3, $$4, $$5, $$6, $$7, $$8, $$9, $$10 $$11, $$12}'

NAME = libftprintf.a
#FLAGS = -g -Werror -Wall -Wextra
FLAGS = 

LIB_PATH = libft/
LIB_NAME = libft.a
SRCS_PATH = srcs/
SRC_FILE = ft_flag.c ft_option.c ft_printf.c ft_specifier1.c ft_width.c \
		    ft_length.c ft_precision.c ft_resolve.c ft_specifier2.c main.c \
			ft_fonction.c


SRC = $(addprefix $(SRCS_PATH)/,$(SRC_FILE))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))


OBJ = $(patsubst srcs/%.c,./%.o,$(SRC))
INC = -I includes/

.SILENT:

all : $(NAME)

$(NAME): $(OBJ)

			make -C libft/ re
						gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
								echo "${BGreen}[ ✔ ] libft.a \n" | ${AWK}
			printf "\033[42m${BWhite} [ ft_printf ] [ OK ] ${Off}\n" | ${AWK}

./%.o: srcs/%.c
			gcc $(FLAGS) $(INC) -c $< -o $@
			printf "${BGreen}[ ✔ ] $<\n" | ${AWK}

clean:
		make clean -C libft
					rm -f $(OBJ)
							printf "${BRed}[ ✔ ] Clean${Off}\n" | ${AWK}

fclean: clean
		make fclean -C libft
					rm -f $(NAME)
							printf "${BRed}[ ✔ ] FClean${Off}\n" | ${AWK}

					printf "\033[42m${BWhite} <([ FCLEAN ])> ${Off}\n" | ${AWK}

re: fclean all

.PHONY: all clean fclean re
