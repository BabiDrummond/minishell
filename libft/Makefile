NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include/

SRCS_DIR = src/
SRCS = charft/ft_isdigit.c	\
	charft/ft_isspace.c		\
	charft/ft_putchar.c		\
	hsft/hash_int_knuth.c	\
	hsft/hs_add.c			\
	hsft/hs_foreach.c		\
	hsft/hs_free.c			\
	hsft/hs_from_lst.c		\
	hsft/hs_new.c			\
	hsft/hs_node_new.c		\
	hsft/hs_resize.c		\
	listft/lst_add_after.c	\
	listft/lst_add_before.c	\
	listft/lst_add_first.c	\
	listft/lst_add_last.c	\
	listft/lst_delete_all.c	\
	listft/lst_delete_node.c\
	listft/lst_delete.c		\
	listft/lst_detach.c		\
	listft/lst_dup.c		\
	listft/lst_foreach.c	\
	listft/lst_is_detached.c\
	listft/lst_is_equal.c	\
	listft/lst_is_first.c	\
	listft/lst_is_invalid.c	\
	listft/lst_is_last.c	\
	listft/lst_merge_sort.c	\
	listft/lst_new_node.c	\
	listft/lst_pop.c		\
	listft/lst_push.c		\
	listft/lst_sum.c		\
	mathft/ft_abs.c			\
	mathft/ft_atoi.c		\
	mathft/ft_is_prime.c	\
	mathft/ilog2_ceil.c		\
	mathft/ilog2.c			\
	mathft/next_prime.c		\
	memft/ft_calloc.c		\
	memft/ft_memcpy.c		\
	memft/ft_memset.c		\
	stringft/free_split.c	\
	stringft/ft_is_number.c	\
	stringft/ft_putstr.c	\
	stringft/ft_split.c		\
	stringft/ft_strchr.c	\
	stringft/ft_strjoin.c	\
	stringft/ft_strlen.c	\
	stringft/ft_strncmp.c	\
	stringft/put_str.c		\
	stringft/str_dup.c		\
	stringft/str_free.c		\
	stringft/str_new_char.c	\
	stringft/str_new_values.c\
	stringft/str_new.c
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