# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 05:26:55 by bhamdi            #+#    #+#              #
#    Updated: 2018/09/19 12:48:18 by bhamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Off=\033[0m             # Color off
BRed=\033[0;31m         # Red
BGreen=\033[1;32m       # Green
BWhite=\033[1;37m       # White

AWK = awk '{print $$1, $$2, $$3, $$4, $$5, $$6, $$7, $$8, $$9, $$10 $$11, $$12}'

NAME = libftprintf.a
CC = clang
FLAGS = -g -Werror -Wall -Wextra

SRCS_PATH = srcs/
SRC_FILE = ft_flag.c ft_option.c ft_printf.c ft_specifier1.c ft_specifier2.c \
		   ft_fonction.c ft_fonction1.c ft_fonction2.c main.c


SRC = $(addprefix $(SRCS_PATH)/,$(SRC_FILE))

OBJ = $(patsubst srcs/%.c,./%.o,$(SRC))
INC = -I includes/

.SILENT:

all : $(NAME)

$(NAME): $(OBJ)
		
		printf "\n\033[42m${BWhite} RULE: make => [ ft_printf ]....[ OK ] \
			${Off}\n\n" | ${AWK}
		
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
		
		printf "\033[42m${BWhite} [ ft_printf ]..................[ OK ] \
			${Off}\n\n" | ${AWK}

./%.o : $(SRCS_PATH)%.c
	gcc $(FLAGS) $(INC) -c $< -o $@
	
		printf "${BGreen}[ ✔ ] $<\n" | ${AWK}


clean:		
	
	rm -f $(OBJ)
	
		printf "${BRed}[ ✔ ] Clean${Off}\n" | ${AWK}
		printf "\033[42m${BWhite} RULE: clean => [ ft_printf ]...[ OK ] \
			${Off}\n\n" | ${AWK}

fclean:
	
	rm -f $(OBJ)
		
		printf "${BRed}[ ✔ ] Clean${Off}\n" | ${AWK}
	
	rm -f $(NAME)
		
		printf "${BRed}[ ✔ ] FClean${Off}\n" | ${AWK}
		printf "\n\033[42m${BWhite} RULE: fclean => [ ft_printf ]..[ OK ] \
			${Off}\n\n" | ${AWK}

re: fclean all

.PHONY: all clean fclean re
