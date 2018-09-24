NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = ./srcs/
OBJ_DIR = ./obj/

SRC = ft_lstadd.c ft_memdel.c ft_size.c ft_striteri.c ft_strnstr.c \
	  ft_lstdel.c ft_memmove.c ft_space.c ft_strjoin.c ft_strrchr.c \
	  ft_atoi.c ft_lstdelone.c ft_memset.c ft_strcat.c ft_strlcat.c \
	  ft_strsplit.c ft_bzero.c ft_lstiter.c ft_putchar.c ft_strchr.c \
	  ft_strlen.c ft_strstr.c ft_count_word.c ft_lstmap.c ft_putchar_fd.c \
	  ft_strclr.c ft_strmap.c ft_strsub.c ft_isalnum.c ft_lstnew.c \
	  ft_putendl.c ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isalpha.c \
	  ft_memalloc.c ft_putendl_fd.c ft_strcpy.c ft_strncat.c ft_tolower.c \
	  ft_isascii.c ft_memccpy.c ft_putnbr.c ft_strdel.c ft_strncmp.c \
	  ft_toupper.c ft_isdigit.c ft_memchr.c ft_putnbr_fd.c ft_strdup.c \
	  ft_strncpy.c ft_trim_space.c ft_isprint.c ft_memcmp.c ft_putstr.c \
	  ft_strequ.c ft_strnequ.c ft_itoa.c ft_memcpy.c ft_putstr_fd.c  \
	  ft_striter.c ft_strnew.c ft_len_base.c ft_itoa_base.c


OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I includes -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
