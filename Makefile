NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -Iinclude/ \
	-Isrc/heredoc/ \
	-Isrc/lexer/ \
	-Isrc/parser/ \
	-Ilibft/include -Ilibft \
	-Ilibft/include/charft \
	-Ilibft/include/gcft \
	-Ilibft/include/hsft \
	-Ilibft/include/listft \
	-Ilibft/include/mathft \
	-Ilibft/include/memft \
	-Ilibft/include/stringft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE = -lreadline
READLINE_DIR = /opt/homebrew/opt/readline

READLINE_INC = -I$(READLINE_DIR)/include
READLINE_LIB = -L$(READLINE_DIR)/lib -lreadline

SRCS_DIR = src
SRCS = main.c 							\
	lexer/errors/syntax_error.c			\
	lexer/utils/create_token_result.c	\
	lexer/utils/get_char_type.c			\
	lexer/utils/initialize_operators.c	\
	lexer/utils/print_token.c			\
	lexer/utils/print_tokens.c			\
	lexer/create_token.c				\
	lexer/create_word.c					\
	lexer/get_next_token.c				\
	lexer/tokenize.c					\
	parser/has_syntax_error.c 			\
	parser/parser.c 					\
	parser/print_ast.c 					\
	heredoc/collect_heredocs.c 			\
	heredoc/should_collect_heredoc.c
OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(READLINE_LIB)
	@echo -n "\033[0;32mGenerated minishell\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) $(READLINE_INC) -c $< -o $@
	@echo "\033[95mCompiling $(notdir $<)"

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)

clean:
	@echo "\033[0;34mCleaning minishell objects"
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[0;34mCleaning minishell"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(LIBFT) clean fclean re bonus