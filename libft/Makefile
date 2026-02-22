NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include/

SRCS_DIR = src/
SRCS = char/ft_isalnum.c	\
	char/ft_isalpha.c		\
	char/ft_isdigit.c		\
	lst/lst_add_back.c		\
	lst/lst_last.c			\
	lst/lst_new.c			\
	lst/lst_size.c			\
	matrix/ft_matrix_print.c \
	mem/ft_free.c			\
	mem/ft_bzero.c			\
	mem/ft_calloc.c			\
	mem/ft_memcpy.c			\
	str/ft_join_split.c		\
	str/ft_split_free.c		\
	str/ft_split_size.c		\
	str/ft_split.c			\
	str/ft_strchr.c			\
	str/ft_strdup.c			\
	str/ft_strjoin_free.c	\
	str/ft_triple_join.c	\
	str/ft_strlen.c			\
	str/ft_strcmp.c			\
	str/ft_strncmp.c		\
	str/ft_substr.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[0;32mGenerated libft.a\033[0m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[95mCompiling \033[0m$(notdir $<)"

clean:
	@echo "\033[0;34mCleaning libft objects\033[0m"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "\033[0;34mCleaning libft\033[0m"
	@rm -f $(NAME)

re:	fclean all