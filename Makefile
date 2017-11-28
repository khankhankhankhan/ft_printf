.PHONY: all, $(NAME), clean, fclean, re
NAME = libftprintf.a
CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBDIR = .
SRCDIR = src
OBJDIR = .
INCDIR = libft/
LFT_PATH = ./libft/

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


OBJ_PATH = ./obj/
LFT_PATH = ./libft/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


OBJ_NAME = $(SRC:.c=.o)

INC_NAME = fillit.h

LIBS = $(addprefix $(LIBDIR)/, $(LIB))
LIBS_DIRS = $(sort $(dir $(LIBS)))

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_PATH), $(patsubst %.c, %.o,$(SRC)))
OBJS_DIRS = $(sort $(dir $(OBJS)))

INCDIR += $(LIBS_DIRS)
INCS = $(addprefix -I , $(INCDIR))

TEMPNAME = $(addprefix $(OBJDIR)/, $(NAME))
DEVMAIN_OBJ = $(addprefix $(OBJ_PATH), $(patsubst %.c, %.o,$(DEVMAIN)))

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) -o $@ -c $<
	@echo -n .
$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	ar rc $(TEMPNAME) $(OBJS)
	libtool -static -o $(NAME) $(TEMPNAME) $(LIBS)
	ranlib $(NAME)

clean:
	make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FILLIT:\t\tRemoving OBJ path: ./obj/$(NOC)"
fclean: clean
	make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FILLIT:\t\tRemoving fillit executable$(NOC)"
re: fclean all
