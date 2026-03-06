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
	builtins/builtin_cd.c		\
	builtins/builtin_echo.c		\
	builtins/builtin_env.c		\
	builtins/builtin_export.c	\
	builtins/builtin_pwd.c		\
	builtins/builtin_unset.c	\
	utils/envp_to_lst.c			\
	utils/extract_key.c			\
	utils/extract_value.c		\
	utils/is_valid_key.c		\
	var/var_clear.c				\
	var/var_create.c			\
	var/var_get.c				\
	var/var_set.c				\
	var/var_unset.c				\
	var/var_update.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

TEST_NAME = test_runner
TEST_DIR = test/
TEST_SRCS = $(TEST_DIR)main.c \
			$(TEST_DIR)builtins/test_builtin_echo.c \
			$(TEST_DIR)builtins/test_builtin_export.c \
			$(TEST_DIR)builtins/test_builtin_unset.c \
			$(TEST_DIR)builtins/test_builtin_env.c \
			$(TEST_DIR)builtins/test_builtin_pwd.c

TEST_OBJS = $(filter-out $(OBJS_DIR)main.o, $(OBJS))

TEST_EXEC = $(TEST_DIR)$(TEST_NAME)

all: $(NAME)

test: $(LIBFT) $(OBJS)
	@echo "\033[0;33mCompiling tests...\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) $(TEST_SRCS) $(TEST_OBJS) $(LIBFT) -o $(TEST_EXEC)
	@echo "\033[0;32mRunning tests...\033[0m"
	@./$(TEST_EXEC)

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
	@rm -f $(TEST_EXEC)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(LIBFT) clean fclean re bonus