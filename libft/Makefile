# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 17:24:29 by apieropa          #+#    #+#              #
#    Updated: 2014/01/25 18:30:16 by apieropa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# General options
FGCC			= no
ifeq ($(FGCC), no)
CC				= gcc
else
CC				= llvm-gcc
endif
RM				= /bin/rm
# Flags
LDFLAGS			= -I $(DIR_INC)
DEBUG			= no
ifeq ($(DEBUG), no)
CFLAGS			= -Wall -Werror -Wextra -pedantic
else
CFLAGS			=
endif
# Directories
DIR_INC			= ./includes
# Files
NAME			= libft.a
OBJ				= $(subst .c,.o,$(SRC))
INC				+= $(DIR_INC)/libft.h
INC				+= $(DIR_INC)/get_next_line.h
INC				+= $(DIR_INC)/ft_printf.h
SRC				+= ft_atoi.c
SRC				+= ft_bzero.c
SRC				+= ft_ctoa.c
SRC				+= ft_isalnum.c
SRC				+= ft_isalpha.c
SRC				+= ft_isascii.c
SRC				+= ft_isdigit.c
SRC				+= ft_isprint.c
SRC				+= ft_itoa.c
SRC				+= ft_lstadd.c
SRC				+= ft_lstadd_end.c
SRC				+= ft_lstdel.c
SRC				+= ft_lstdelone.c
SRC				+= ft_lstelem.c
SRC				+= ft_lstnew.c
SRC				+= ft_lstprint_str.c
SRC				+= ft_lstsize.c
SRC				+= ft_memalloc.c
SRC				+= ft_memccpy.c
SRC				+= ft_memchr.c
SRC				+= ft_memcmp.c
SRC				+= ft_memcpy.c
SRC				+= ft_memdel.c
SRC				+= ft_memmove.c
SRC				+= ft_memset.c
SRC				+= ft_nbrchr.c
SRC				+= ft_nbrlen.c
SRC				+= ft_nbrlen_base.c
SRC				+= ft_power.c
SRC				+= ft_printf.c
SRC				+= ft_printf_b.c
SRC				+= ft_printf_c.c
SRC				+= ft_printf_i.c
SRC				+= ft_printf_m.c
SRC				+= ft_printf_o.c
SRC				+= ft_printf_p.c
SRC				+= ft_printf_s.c
SRC				+= ft_printf_u.c
SRC				+= ft_printf_x.c
SRC				+= ft_printf_xu.c
SRC				+= ft_putchar.c
SRC				+= ft_putchar_fd.c
SRC				+= ft_putendl.c
SRC				+= ft_putendl_fd.c
SRC				+= ft_putnbr.c
SRC				+= ft_putnbr_base.c
SRC				+= ft_putnbr_fd.c
SRC				+= ft_putstr.c
SRC				+= ft_putstr_debug.c
SRC				+= ft_putstr_fd.c
SRC				+= ft_strcat.c
SRC				+= ft_strchr.c
SRC				+= ft_strclr.c
SRC				+= ft_strcmp.c
SRC				+= ft_strcpy.c
SRC				+= ft_strcut.c
SRC				+= ft_strdel.c
SRC				+= ft_strdel_chr.c
SRC				+= ft_strdup.c
SRC				+= ft_strequ.c
SRC				+= ft_striter.c
SRC				+= ft_striteri.c
SRC				+= ft_strjoin.c
SRC				+= ft_strlcat.c
SRC				+= ft_strlen.c
SRC				+= ft_strmap.c
SRC				+= ft_strmapi.c
SRC				+= ft_strncat.c
SRC				+= ft_strnchr.c
SRC				+= ft_strncmp.c
SRC				+= ft_strncpy.c
SRC				+= ft_strndup.c
SRC				+= ft_strnequ.c
SRC				+= ft_strnew.c
SRC				+= ft_strnstr.c
SRC				+= ft_strrchr.c
SRC				+= ft_strrev.c
SRC				+= ft_strsplit.c
SRC				+= ft_strsplit_av.c
SRC				+= ft_strstr.c
SRC				+= ft_strsub.c
SRC				+= ft_strtrim.c
SRC				+= ft_strtrim_chr.c
SRC				+= ft_tolower.c
SRC				+= ft_toupper.c
SRC				+= get_next_line.c
# Messages
MSG_BUILD		= @echo "\033[0;32m[build]" | tr -d '\n'
MSG_REMOVE		= @echo "\033[0;31m[remove]" | tr -d '\n'
MSG_CLOSE		= @echo "\033[0m" | tr -d '\n'
ifeq ($(DEBUG), no)
MSG_MODE		= @echo "\033[1;34m[release_mode]" | tr -d '\n'
else
MSG_MODE		= @echo "\033[0;35m[debug_mode]" | tr -d '\n'
endif

# Classic Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(MSG_MODE)
	$(MSG_BUILD)
	ar -rcs $@ $(OBJ)
	$(MSG_CLOSE)

%.o: %.c $(INC)
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

clean:
	$(MSG_REMOVE)
	$(RM) -f $(OBJ)
	$(MSG_CLOSE)

fclean: clean
	$(MSG_REMOVE)
	$(RM) -f $(NAME)
	$(MSG_CLOSE)

re: fclean all

.PHONY: all re clean fclean
