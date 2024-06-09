C_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,%.o,$(C_FILES))
HDR_FILES = libft.h

TEST_FILES = $(wildcard tests/*.c)
TEST_OBJS = $(patsubst %.c,%.o,$(TEST_FILES))

OUT = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

all: $(OUT)

$(OUT): $(OBJ_FILES) $(HDR_FILES)
	$(AR) $(ARFLAGS) $@ $?

$(OBJ_FILES): %.o:%.c

test: $(TEST_OBJS) 

$(TEST_OBJS): $(TEST_FILES) $(OUT)
	$(CC) $< -o $@ -I. -L. -lft

clean reclean:
	rm -f $(OBJ_FILES) $(TEST_OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all reclean

.PHONY: all fclean reclean re test
