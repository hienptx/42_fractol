# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 14:55:05 by hipham            #+#    #+#              #
#    Updated: 2024/05/30 17:36:30 by hipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# @ is added before each command to suppress echoing.

# Variable Naming
MLX_PATH := ./MLX42
MLX_INCL := ./MLX42/include/MLX42
LIBFT_PATH := ./libft
LIBFT_INCL := ./libft/includes
PRINTF_PATH := ./printf
SRCS_PATH := ./srcs
OBJS_PATH := ./objs

#Program name
NAME := fractol

# Compiler
CC := gcc
CFLAGS := -Wextra -Wall -Werror -I./includes

# Dependency Handling
LIBFT := $(LIBFT_PATH)/libft.a
PRINTF := $(PRINTF_PATH)/ftprintf.a
MLX_LIB := $(MLX_PATH)/build/libmlx42.a
MLX := -L$(MLX_PATH)/build -lmlx42 -ldl -lglfw -pthread -lm

SRCS := fractol.c ft_render.c ft_coloring.c fractol_sets.c fractol_utils.c hook_events.c args_handling.c
OBJS_O := $(SRCS:.c=.o)

#objects 
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_O))

# Targets
.PHONY: all clean fclean re libmlx

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@echo "Initializing and updating submodules..."
	@git submodule update --init --recursive
	@echo "Building MLX42 library..."
	@cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -I$(MLX_INCL) -I$(LIBFT_INCL) $(OBJS) -o $@ $(MLX) $(PRINTF) $(LIBFT)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)
	
$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c | $(OBJS_PATH)
	@$(CC) -I$(MLX_INCL) -I$(LIBFT_INCL) $(CFLAGS) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(PRINTF):
	@make -C $(PRINTF_PATH)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_PATH)
	@rm -rf $(MLX_PATH)/build
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT) fclean
	@rm -rf $(PRINTF) fclean

re: fclean all
