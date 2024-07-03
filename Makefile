SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
HDR_FILES = libft.h 

BUILD_DIR = build

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $?

$(BUILD_DIR)/%.o: %.c $(HDR_FILES) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean reclean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

info:
	$(info $(SRC_FILES))

.PHONY: all clean fclean reclean re info
