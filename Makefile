NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./include/

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE = -lreadline

SRCS_DIR = src/
SRCS = main.c 							\
	builtins/builtin_cd.c				\
	builtins/builtin_echo.c				\
	builtins/builtin_env.c				\
	builtins/builtin_exit.c				\
	builtins/builtin_export.c			\
	builtins/builtin_pwd.c				\
	builtins/builtin_unset.c			\
	execution/execute_cmd.c				\
	execution/execute_builtin_cmd.c		\
	execution/execute_external_cmd.c	\
	execution/execute_operator.c		\
	execution/execute.c					\
	execution/find_cmd_path.c			\
	execution/process_redirects.c		\
	expansion/build_argv.c				\
	expansion/expand_redirect.c			\
	expansion/expand_string.c			\
	expansion/expand.c					\
	expansion/split_unquoted.c			\
	heredoc/collect_heredocs.c 			\
	heredoc/redirect_heredoc.c			\
	heredoc/split_content_heredoc.c		\
	lexer/create_token_result.c			\
	lexer/get_char_type.c				\
	lexer/create_token.c				\
	lexer/create_word.c					\
	lexer/get_next_token.c				\
	lexer/init_lexer_operators.c		\
	lexer/tokenize.c					\
	parser/build_ast_node.c 			\
	parser/parser_syntax_error.c 		\
	parser/init_ast_operators.c			\
	parser/parser.c 					\
	signals/signals.c					\
	utils/envp_to_lst.c					\
	utils/lst_to_envp.c					\
	utils/get_shell_ctx.c				\
	utils/get_trimmed_length.c			\
	utils/print_error.c					\
	var/extract_key.c					\
	var/extract_value.c					\
	var/is_valid_key.c					\
	var/var_create.c					\
	var/var_get.c						\
	var/var_set.c						\
	var/var_unset.c						\
	var/var_update.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

VALGRIND = valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --track-fds=yes

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(READLINE)
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

valgrind: all
	$(VALGRIND) ./$(NAME)

re: fclean all

.PHONY: $(LIBFT) clean fclean re bonus