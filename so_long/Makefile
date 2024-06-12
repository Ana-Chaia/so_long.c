# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 12:19:22 by anacaro5          #+#    #+#              #
#    Updated: 2024/03/16 12:37:02 by anacaro5         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
NAME_BONUS	:= so_long_bonus
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast #-g3

# LIBRARIES_PATH
LIBMLX	:= ./MLX42
LIBFT_PATH = ./libplus
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH 	:= objects
BONUS_PATH	:= sources_bonus
OBONUS_PATH	:= objects_bonus

# SOURCES
CFILES		:= so_long.c file_validation.c so_long_utils.c validation_one.c \
validation_two.c validation_three.c images_one.c images_two.c move_one.c \
move_two.c

CBONUS		:= so_long_bonus.c file_validation_bonus.c so_long_utils_bonus.c \
validation_one_bonus.c validation_two_bonus.c validation_three_bonus.c \
images_one_bonus.c images_two_bonus.c move_one_bonus.c move_two_bonus.c

SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))
SRC_BONUS	:= $(addprefix $(BONUS_PATH)/, $(CBONUS))
OBJ_BONUS	:= $(addprefix $(OBONUS_PATH)/, $(CBONUS:%.c=%.o))

HEADERS	:= -I ./include -I $(LIBMLX)/include
HEADER_FILE := include/so_long.h include/so_long_bonus.h
LIBS_MLX	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

MAKEFLAGS += --silent

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: libmlx $(OBJ_PATH) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus: libmlx libplus $(NAME_BONUS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(HEADER_FILE) | $(OBONUS_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBONUS_PATH):
	@mkdir -p $(OBONUS_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBS_MLX) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)     [$(PURPLE)SO LONG$(WHITE)] has been compiled!✨"
	@echo "$(PURPLE)     GAME ON!!!🚀🧩"
	@echo "$(GREEN)-------------------------------------------"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBS_MLX) $(LIBFT) $(INCLUDES) -o $(NAME_BONUS)
	@echo "$(GREEN)----------------------------------------------"
	@echo "$(WHITE)   The[$(PURPLE)SO LONG BONUS$(WHITE)] has been compiled!✨"
	@echo "$(PURPLE)  GAME ON!!!🚀🧩"
	@echo "$(GREEN)----------------------------------------------"

clean:
	@rm -rf $(OBJS) $(OBONUS_PATH)
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE) SO_LONG object files were cleaned!🧹"
	@echo "$(RED)-----------------------------------"

fclean: clean
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE)        Cleaning all... 🧹"
	@echo "$(RED)-----------------------------------"
	@rm -rf $(NAME) $(NAME_BONUS) $(OBONUS_PATH)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)---------------------------------------"
	@echo "$(WHITE) ✨ SO_LONG full cleaning has been completed! ✨"
	@echo "$(RED)---------------------------------------"

re: clean all

.PHONY: all, clean, fclean, re, libmlx