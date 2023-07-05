NAME := push_swap

LIBFT = libftprintf.a
LIBFT_DIR = ./libftprintf
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_FLAGS = -I$(LIBFT_DIR)/include -I$(LIBFT_DIR)/libft/include
LIBFT_LIB_FLAGS = -L$(LIBFT_DIR) -lftprintf

SRC_DIR := src
OBJS_DIR := obj
INC_DIR := include

HEADERS := $(addprefix $(INC_DIR)/, \
				push_swap.h \
				)

vpath %.c \
	$(SRC_DIR)

SRCS := \
		$(SRC_DIR)/push_swap.c
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

CC := cc
CFLAGS := -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFT_INC_FLAGS) $(LIBFT_LIB_FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o : %.c
	$(info $(shell mkdir -p $(OBJS_DIR)))
	$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFT_INC_FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_FILE)

$(LIBFT_FILE):
	@make --silent --no-print-directory -C $(LIBFT_DIR)
	@printf "Created printflibft\n"

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