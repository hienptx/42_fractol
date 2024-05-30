NAME = ftprintf.a

CC = CC
CFLAGS = -Wall -Wextra -Werror -I./includes
DEBUG = -g

SRC_PATH = srcs
OBJ_PATH = objs

SOURSES = ft_printf.c ft_putchr.c ft_putstr.c ft_putnbr.c ft_putunbr.c \
ft_puthex.c ft_putptr.c

OBJ_O = ${SOURSES:.c=.o}

OBJS = $(addprefix $(OBJ_PATH)/, $(OBJ_O))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating archive: $(NAME)"
	@ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

# NAME = ftprintf.a

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -I./includes
# DEBUG = -g

# SRC_PATH = srcs
# OBJ_PATH = objs

# SOURCES = ft_printf.c ft_putchr.c ft_putstr.c ft_putnbr.c ft_putunbr.c \
#           ft_puthex.c ft_putptr.c

# OBJS = $(addprefix $(OBJ_PATH)/, $(SOURCES:.c=.o))

# all: $(NAME)

# $(NAME): $(OBJS)
# 	ar rcs $@ $^

# $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
# 	$(CC) $(CFLAGS) -o $@ -c $<

# $(OBJ_PATH):
# 	mkdir -p $(OBJ_PATH)

# clean:
# 	rm -rf $(OBJ_PATH)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all
