NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE = -lreadline

SRCS_DIR = src/
SRCS = main.c 					\
	builtins/build_cmd_path.c	\
	builtins/builtin_echo.c		\
	builtins/builtin_env.c		\
	builtins/builtin_pwd.c		\
	builtins/var_create.c		\
	builtins/var_get.c			\
	builtins/var_set.c			\
	builtins/var_update.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(READLINE)
	@echo "\033[0;32mGenerated minishell\033[0m"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[95mCompiling \033[0m$(notdir $<)"

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@echo "\033[0;34mCleaning minishell objects\033[0m"
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[0;34mCleaning minishell\033[0m"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(LIBFT) clean fclean re bonus