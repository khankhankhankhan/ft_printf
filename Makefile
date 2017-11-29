.PHONY: all, $(NAME), clean, fclean, re
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_itoa_base.c\
	ft_printf.c\
	ft_print_hex.c\
	ft_print1.c\
	ft_print_octal.c\
	ft_print_decimal.c\
	ft_print_undec.c\
	ft_print_point.c\
	ft_print_char.c\
	ft_print_str.c\
	ft_print_float.c

SRCS_LIB = ft_memset.c	ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
						ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
						ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
						ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
						ft_atoi.c ft_isalpha.c ft_isdigit.c	ft_isalnum.c ft_isascii.c\
						ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
						ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
						ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
						ft_strjoin.c ft_strtrim.c ft_strgetworld.c ft_strsplit.c\
						ft_getnsize.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c\
						ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
						ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
						ft_lstadd.c ft_lstiter.c ft_lstmap.c

LDIR		=	./libft/
SRCSDIR		=	./

OBJS			=	$(subst .c,.o,$(SRCS))
OBJS_LIB		=	$(subst .c,.o,$(SRCS_LIB))
LIST_OBJ		=	$(addprefix $(SRCSDIR), $(OBJS))
LIST_OBJ_LIB	=	$(addprefix $(LDIR), $(OBJS_LIB))

RE			= \033[0;31m
GR			= \033[0;32m
YE			= \033[0;33m
BL			= \033[0;34m
WH			= \033[0;38m
OK			= $(WH)* [ $(GR)OK $(WH)]
KO			= $(WH)* [ $(RE)KO $(WH)]
W8			= $(WH)* [ $(BL)W8 $(WH)]

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./ -c -o $@ $<

$(NAME): $(LIST_OBJ) $(LIST_OBJ_LIB)
	ar rc $(NAME) $(LIST_OBJ) $(LIST_OBJ_LIB)
	ranlib $(NAME)

clean:
	@echo "$(W8) $(YE)/bin/rm -rf $(LIST_OBJ) $(LIST_OBJ_LIB)$(WH)"
	@/bin/rm -rf $(LIST_OBJ) $(LIST_OBJ_LIB)
	@echo "$(OK) $(GR)Done!$(WH)"

fclean: clean
	@echo "$(W8) $(YE)/bin/rm -rf $(NAME)$(WH)"
	@/bin/rm -rf $(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

re: fclean all

.PHONY: all clean fclean re
