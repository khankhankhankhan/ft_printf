.PHONY: all, $(NAME), clean, fclean, re
NAME = libftprintf.a
CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBDIR = .
SRCDIR = src
OBJDIR = .
INCDIR = libft/

LIB = libft/libft.a
SRC = ft_itoa_base.c\
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

DEVNAME = ft_printf
DEVMAIN = main.c

LIBS = $(addprefix $(LIBDIR)/, $(LIB))
LIBS_DIRS = $(sort $(dir $(LIBS)))

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o,$(SRC)))
OBJS_DIRS = $(sort $(dir $(OBJS)))

INCDIR += $(LIBS_DIRS)
INCS = $(addprefix -I , $(INCDIR))

TEMPNAME = $(addprefix $(OBJDIR)/, $(NAME))
DEVMAIN_OBJ = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o,$(DEVMAIN)))

all: $(NAME)
$(NAME): build $(LIBS) $(OBJS)
	ar rc $(TEMPNAME) $(OBJS)
	libtool -static -o $(NAME) $(TEMPNAME) $(LIBS)
	ranlib $(NAME)
build:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJS_DIRS)
clean:
	rm -f $(TEMPNAME)
	rm -f $(LIBS)
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all


$(LIBDIR)/%.a:
	make -s -C $(@D)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(INCS) $(CFLAGS)
