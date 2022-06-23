NAME = philo

# Config
# ****************************************************************************

CC = gcc
CFLAGS := -I includes/ #-Wall -Wextra -Werror
# DEBUG = -g -fsanitize=address

# Source files
# ****************************************************************************

MAIN_DIR	=	main/
MAIN_FILES	=	main.c
MAIN_SRCS	=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

ERROR_DIR	=	error/
ERROR_FILES	=	error.c
ERROR_SRCS	=	$(addprefix $(ERROR_DIR), $(ERROR_FILES))

PARSE_DIR	=	parse/
PARSE_FILES	=	parse.c \
				wrap_atoi.c
PARSE_SRCS	=	$(addprefix $(PARSE_DIR), $(PARSE_FILES))

STRUCT_DIR	=	struct/
STRUCT_FILES	=	arguments.c
STRUCT_SRCS	=	$(addprefix $(STRUCT_DIR), $(STRUCT_FILES))

SRC_FILES =			$(MAIN_SRCS) \
					$(ERROR_SRCS) \
					$(PARSE_SRCS) \
					$(STRUCT_SRCS)

# addprefix

SRC_DIR = srcs/

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJS = $(MAIN_FILES:%.c=$(OBJ_DIR)main/%.o)
ERROR_OBJS = $(ERROR_FILES:%.c=$(OBJ_DIR)error/%.o)
PARSE_OBJS = $(PARSE_FILES:%.c=$(OBJ_DIR)parse/%.o)
STRUCT_OBJS = $(STRUCT_FILES:%.c=$(OBJ_DIR)struct/%.o)

# Recipe
# ****************************************************************************

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(MAIN_DIR)
	mkdir -p $(OBJ_DIR)$(ERROR_DIR)
	mkdir -p $(OBJ_DIR)$(PARSE_DIR)
	mkdir -p $(OBJ_DIR)$(STRUCT_DIR)

debug: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	rm -fr *.dSYM

fclean:
	rm -rf $(NAME) $(OBJ_DIR)
	rm -fr *.dSYM

re: fclean all
.PHONY: all clean fclean re
