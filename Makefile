C_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c,%.o,$(C_FILES))
HDR_FILES = libft.h

OUT = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rc

all: $(OUT)

$(OUT): $(OBJ_FILES) $(HDR_FILES)
	$(AR) $(ARFLAGS) $@ $?

$(OBJ_FILES): %.o:%.c

clean reclean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(OUT)

re: fclean all reclean

.PHONY: all fclean all reclean re
