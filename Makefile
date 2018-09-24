CC = gcc
FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude
LDFLAGS = -Llibft
LDLIBS = -lft

NAME = libftprintf.a

NAME_PROJECT = ft_printf

SRC_PATH = srcs/
LIB_PATH = libft
SRCLIB_PATH = $(LIB_PATH)/srcs
INC_PATH = includes/
OBJ_PATH = obj/
OBJLIB_PATH = libft/obj/

SRC_NAME = ft_flag.c ft_option.c ft_printf.c ft_specifier1.c ft_specifier2.c \
		   ft_fonction.c ft_fonction1.c ft_fonction2.c 

LIB_NAME = ft_atoi.c ft_bzero.c ft_space.c ft_isdigit.c ft_memalloc.c \
		   ft_memset.c ft_strchr.c ft_strlen.c 

INC_NAME = ft_printf.h
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/, $(OBJLIB_NAME))

all: $(NAME)
	 
$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@make -C $(LIB_PATH)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"
	@echo "It's finish !\n\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(SRCLIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -I libft/includes -o $@ -c $<

clean:
	@make -C $(LIB_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[1;34m$(NAME_PROJECT)\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"	
