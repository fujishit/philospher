NAME = philo

# Config
# ****************************************************************************

CC = gcc
CFLAGS := -I includes/ -pthread -Wall -Wextra -Werror
DEBUG = -g -fsanitize=thread #-fsanitize=address
#CFLAGS += $(DEBUG)

# Source files
# ****************************************************************************

MAIN_DIR	=	main/
MAIN_FILES	=	main.c \
				create_philos.c \
				create_mutex.c \
				validate.c \
				get_msec.c \
				simulate.c \
				action_philo.c \
				action_eat.c \
				action_sleep.c \
				action_think.c \
				watch_simulate.c

MAIN_SRCS	=	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

PARSE_DIR	=	parse/
PARSE_FILES	=	parse.c \
				wrap_atoi.c
PARSE_SRCS	=	$(addprefix $(PARSE_DIR), $(PARSE_FILES))

STRUCT_DIR	=	struct/
STRUCT_FILES	=	arguments.c \
					philosopher.c
STRUCT_SRCS	=	$(addprefix $(STRUCT_DIR), $(STRUCT_FILES))

ERROR_DIR	=	error/
ERROR_FILES	=	error.c
ERROR_SRCS	=	$(addprefix $(ERROR_DIR), $(ERROR_FILES))

SRC_FILES =			$(MAIN_SRCS) \
					$(ERROR_SRCS) \
					$(PARSE_SRCS) \
					$(VALIDATE_SRCS) \
					$(STRUCT_SRCS)

# addprefix

SRC_DIR = srcs/

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJS = $(MAIN_FILES:%.c=$(OBJ_DIR)$(MAIN_DIR)%.o)
PARSE_OBJS = $(PARSE_FILES:%.c=$(OBJ_DIR)$(PARSE_DIR)%.o)
VALIDATE_OBJS = $(VALIDATE_FILES:%.c=$(OBJ_DIR)$(VALIDATE_DIR)%.o)
STRUCT_OBJS = $(STRUCT_FILES:%.c=$(OBJ_DIR)(STRUCT_DIR)%.o)
ERROR_OBJS = $(ERROR_FILES:%.c=$(OBJ_DIR)$(ERROR_DIR)%.o)

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
	mkdir -p $(OBJ_DIR)$(PARSE_DIR)
	mkdir -p $(OBJ_DIR)$(VALIDATE_DIR)
	mkdir -p $(OBJ_DIR)$(STRUCT_DIR)
	mkdir -p $(OBJ_DIR)$(ERROR_DIR)

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
