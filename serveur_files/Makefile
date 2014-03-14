# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/24 13:48:56 by apieropa          #+#    #+#              #
#    Updated: 2014/02/09 15:59:49 by apieropa         ###   ########.fr        #
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
DEBUG			= no
ifeq ($(DEBUG), no)
CFLAGS			= -Wall -Werror -Wextra
else
CFLAGS			=
endif
LDFLAGS			+= -I $(DIR_INC)
CLIBFLAGS		= -L $(DIR_LIBFT) -lft
# Directories
DIR_SRC			= ./src
DIR_OBJ			= ./obj
DIR_INC			= ./inc
DIR_LIBFT		= ./../libft
# Files
NAME			= ./../serveur
OBJ				= $(subst .c,.o,$(subst $(DIR_SRC),$(DIR_OBJ),$(SRC)))
SRC				+= $(DIR_SRC)/main.c
SRC				+= $(DIR_SRC)/t_str.c
SRC				+= $(DIR_SRC)/t_pidlist.c
SRC				+= $(DIR_SRC)/uncompress.c
SRC				+= $(DIR_SRC)/print.c
INC				+= $(DIR_INC)/serveur.h
LIBFT			= $(DIR_LIBFT)/libft.a
# Messages
MSG_BUILD		= @echo "\033[0;32m[build]" | tr -d '\n'
MSG_REMOVE		= @echo "\033[0;31m[remove]" | tr -d '\n'
MSG_CLOSE		= @echo "\033[0m" | tr -d '\n'
ifeq ($(DEBUG), no)
MSG_MODE		= @echo "\033[1;34m[release_mode]" | tr -d '\n'
else
MSG_MODE		= @echo "\033[0;35m[debug_mode]" | tr -d '\n'
endif

# Classic rules:
all: $(LIBFT) $(NAME)

$(NAME): $(DIR_OBJ) $(OBJ)
	$(MSG_MODE)
	$(MSG_BUILD)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS) $(CLIBFLAGS)
	$(MSG_CLOSE)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

$(DIR_OBJ):
	mkdir obj

$(LIBFT):
	make -f Makefile -C $(DIR_LIBFT)

clean:
	$(MSG_REMOVE)
	$(RM) -f $(OBJ)
	$(MSG_CLOSE)

fclean: clean
	$(MSG_REMOVE)
	$(RM) -f $(NAME)
	$(MSG_CLOSE)

re: fclean all

.PHONY: all re a clean fclean $(LIBFT)

# Supp rules:
a:
	make re DEBUG=yes
