LIB_NAME := libft.a
HEADER_FILE := libft.h

SRC_DIR := srcs
OBJS_DIR := obj
HEADER_DIR := include

SRC_FILES := ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_putstr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c 
OBJECTS := $(SRC_FILES:.c=.o)

SRC_PATHS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_PATHS := $(addprefix $(OBJS_DIR)/, $(OBJECTS))
HEADER_PATHS = $(addprefix $(HEADER_DIR)/, $(HEADER_FILE))
TEST_FILE = $(patsubst %.c,%,$(lastword $(SRC_FILES)))

CC := cc
CFLAGS := -Wall -Wextra -Werror

all : directories $(LIB_NAME)

directories : $(OBJS_DIR)/

$(OBJS_DIR)/ :
	$(info $(shell mkdir -p $@))

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

$(LIB_NAME) : $(OBJ_PATHS)
	ar -rc $@ $^
	ranlib $@

clean :
	rm -f $(OBJ_PATHS)

fclean : clean
	rm -f $(LIB_NAME)

re : fclean all

.PHONY: all clean fclean re directories