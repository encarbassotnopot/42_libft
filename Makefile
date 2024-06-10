SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES = libft.h

TEST_SRCS = $(wildcard tests/*.c)
TEST_OBJS = $(patsubst %.c,%.o,$(TEST_SRCS))

OUT = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

all: $(OUT)

$(OUT): $(OBJ_FILES) $(HDR_FILES)
	$(AR) $(ARFLAGS) $@ $?

$(OBJ_FILES): %.o:%.c

test: $(TEST_OBJS) 

$(TEST_OBJS): %.o:%.c $(OUT)
	$(CC) -w $< -g -o $@ -I. -L. -lft -lbsd

clean reclean:
	rm -f $(OBJ_FILES) $(TEST_OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all reclean

.PHONY: all fclean reclean re test
