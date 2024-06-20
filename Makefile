SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
HDR_FILES = libft.h

SRC_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))

TEST_SRCS = $(wildcard tests/*.c)
TEST_OBJS = $(patsubst %.c,%.o,$(TEST_SRCS))

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ_FILES) $(HDR_FILES)
	$(AR) $(ARFLAGS) $@ $?

bonus: $(OBJ_BONUS) | $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $?

$(OBJ_FILES): %.o:%.c

test: tests/tests.o

tests/tests.o: $(TEST_OBJS) $(NAME)
	$(CC) -o $@ -g $^ -I. -L. -lft -lbsd

$(TEST_OBJS): %.o:%.c
	$(CC) $? -w -g -c -o $@ -I. -L. -lft -lbsd

clean reclean:
	rm -f $(OBJ_FILES) $(OBJ_BONUS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all reclean

info:
	$(info $(SRC_FILES))
	$(info $(SRC_BONUS))


.PHONY: all fclean reclean re test bonus info
