NAME := libftprintf.a

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include

SRC_DIR := srcs
OBJS_DIR := obj
INC_DIR := include

TEST_FILE = tests.c

HEADERS := $(addprefix $(INC_DIR)/, \
				ft_printf.h \
				printf_int.h \
				printf_hex.h \
				)

SRC_PARSERS_DIR := $(SRC_DIR)/parsers

SRC_PARSERS := $(addprefix $(SRC_PARSERS_DIR)/, \
				ft_init_parse.c	\
				parse_flags.c \
				parse_format.c \
				parse_precision.c \
				parse_specifier.c \
				parse_width.c \
				)

SRC_UTILS_DIR := $(SRC_DIR)/utils

SRC_UTILS := $(addprefix $(SRC_UTILS_DIR)/, \
				initialize_params.c	\
				check_zero_padding.c \
				convert_base_unsigned.c \
				)

SRC_PRINTERS_DIR := $(SRC_DIR)/printers

SRC_PRINTERS := $(addprefix $(SRC_PRINTERS_DIR)/, \
				print_number.c	\
				print_flags_number.c \
				print_char.c \
				print_hex.c \
				print_flags_hex.c \
				print_str.c \
				)

vpath %.c \
	$(SRC_DIR)	\
	$(SRC_UTILS_DIR)	\
	$(SRC_PARSERS_DIR) \
	$(SRC_PRINTERS_DIR)

SRCS := \
		$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/print_init.c \
		$(SRC_PARSERS) \
		$(SRC_UTILS) \
		$(SRC_PRINTERS)
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

CC := cc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	ar -rcs $@ $(OBJS)

$(OBJS_DIR)/%.o : %.c
	$(info $(shell mkdir -p $(OBJS_DIR)))
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(LIBFT): $(LIBFT_FILE)

$(LIBFT_FILE):
	@make --silent --no-print-directory -C $(LIBFT_DIR)
	cp $(LIBFT_FILE) $(NAME)
	@printf "Created libft\n"

$(LIBFT)_clean:
	@make --silent --no-print-directory -C $(LIBFT_DIR) clean

$(LIBFT)_fclean:
	@make --silent --no-print-directory -C $(LIBFT_DIR) fclean

bonus: $(NAME)

test: $(TEST_FILE) $(NAME)
	$(CC) $(CFLAGS) -g -L. -lftprintf -L$(LIBFT_DIR) -lft -I include -I$(LIBFT_INC_DIR) $(TEST_FILE) -o $(TEST_FILE:.c=.out)
	@printf "TestResult:\n"
	@./$(TEST_FILE:.c=.out)
	@rm $(TEST_FILE:.c=.out)
	@rm -rf $(TEST_FILE:.c=.out.dSYM)

clean : $(LIBFT)_clean
	@rm -f $(OBJS)
	@printf "Clean done\n"

fclean : $(LIBFT)_fclean clean
	@rm -f $(NAME)
	@printf "Fclean done\n"

re : fclean all

.PHONY: all clean fclean re bonus test