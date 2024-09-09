NAME		= test_vec3
CC			= cc
WRNFL		= -Wall -Werror -Wextra
DBGFL		= -g3
COMFL		= $(DBGFL) $(WRNFL) -c
LOAFL		=
LLIBS		= -lm
HEADE		= vec3.h
SOURC		= vec3.c \
			  test_vec3.c

OBJET		= $(SOURC:.c=.o)

all: $(NAME)

$(NAME): Makefile $(OBJET)
	$(CC) $(LOAFL) $(OBJET) -o $@ $(LLIBS) -I.

%.o: %.c $(HEADER)
	$(CC) $(COMFL) $< -o $@ -I.

run:
	./$(NAME)
