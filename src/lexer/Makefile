# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 20:00:00 by bcosta-b          #+#    #+#              #
#    Updated: 2026/01/30 19:31:58 by bcosta-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lexer.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ../../libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -I. -I$(LIBFT_DIR)/include -I$(LIBFT_DIR) \
	-I$(LIBFT_DIR)/include/charft \
	-I$(LIBFT_DIR)/include/gcft \
	-I$(LIBFT_DIR)/include/hsft \
	-I$(LIBFT_DIR)/include/listft \
	-I$(LIBFT_DIR)/include/mathft \
	-I$(LIBFT_DIR)/include/memft \
	-I$(LIBFT_DIR)/include/stringft


SRCS = $(wildcard $(SRC_DIR)/*.c) \
       $(wildcard $(SRC_DIR)/utils/*.c) \
       $(wildcard $(SRC_DIR)/errors/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(filter $(SRC_DIR)/%.c,$(SRCS))) \
	$(patsubst $(SRC_DIR)/utils/%.c,$(OBJ_DIR)/utils_%.o,$(filter $(SRC_DIR)/utils/%.c,$(SRCS))) \
	$(patsubst $(SRC_DIR)/errors/%.c,$(OBJ_DIR)/errors_%.o,$(filter $(SRC_DIR)/errors/%.c,$(SRCS)))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)



create_obj_dirs:
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/utils $(OBJ_DIR)/errors



$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c lexer.h | create_obj_dirs
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[95mCompiling $(notdir $<)"

$(OBJ_DIR)/utils_%.o: $(SRC_DIR)/utils/%.c lexer.h | create_obj_dirs
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[95mCompiling utils/$(notdir $<)"

$(OBJ_DIR)/errors_%.o: $(SRC_DIR)/errors/%.c lexer.h | create_obj_dirs
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[95mCompiling errors/$(notdir $<)"

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo -n "\033[0;32mGenerated lexer.a\n"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
