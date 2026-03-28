NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include/

SRCS_DIR = src/
SRCS = ast/ast_new.c		\
	char/ft_isalnum.c		\
	char/ft_isalpha.c		\
	char/ft_isdigit.c		\
	char/ft_isspace.c		\
	gc/create_gc_node.c		\
	gc/gc_free_all.c		\
	gc/get_collector.c		\
	gc/gc_add.c				\
	gc/gc_exit.c			\
	gc/gc_node_free.c		\
	list/lst_add_last.c		\
	list/lst_detach.c		\
	list/lst_pop.c			\
	list/lst_new_head.c		\
	lst/lst_add_back.c		\
	lst/lst_del_node.c		\
	lst/lst_last.c			\
	lst/lst_new.c			\
	lst/lst_size.c			\
	mem/ft_bzero.c			\
	mem/ft_calloc.c			\
	mem/ft_memcpy.c			\
	mem/safe_calloc.c		\
	str/append_char.c		\
	str/ft_itoa.c			\
	str/ft_join_split.c		\
	str/ft_split_size.c		\
	str/ft_split.c			\
	str/ft_strchr.c			\
	str/ft_strdup.c			\
	str/ft_strjoin.c		\
	str/ft_triple_join.c	\
	str/ft_strlen.c			\
	str/ft_strcmp.c			\
	str/ft_strncmp.c		\
	str/ft_strndup.c		\
	str/ft_substr.c			\
	str/ft_replace.c		\
	str/ft_putstr_fd.c		\
	str/merge_splits.c

OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo -n "\033[0;32mGenerated libft.a\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[95mCompiling $(notdir $<)"

clean:
	@echo "\033[0;34mCleaning libft objects"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "\033[0;34mCleaning libft"
	@rm -f $(NAME)

re:	fclean all