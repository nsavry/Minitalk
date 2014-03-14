# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/24 13:48:56 by apieropa          #+#    #+#              #
#    Updated: 2014/02/09 12:57:22 by apieropa         ###   ########.fr        #
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
DIR_SERVEUR		= ./serveur_files
DIR_CLIENT		= ./client_files
DIR_LIBFT		= ./libft
# Files
NAME			+= $(SERVEUR)
NAME			+= $(CLIENT)
SERVEUR			= ./serveur
CLIENT			= ./client
CLIENT2			= ./client2
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
all: $(NAME)

$(NAME):

$(SERVEUR):
	make -f Makefile -C $(DIR_SERVEUR) FGCC=$(FGCC) DEBUG=$(DEBUG)

$(CLIENT):
	make -f Makefile -C $(DIR_CLIENT) FGCC=$(FGCC) DEBUG=$(DEBUG)

clean:
	$(MSG_REMOVE)
	$(RM) -f $(SERVEUR)
	$(RM) -f $(CLIENT)
	$(RM) -f $(CLIENT2)
	$(MSG_CLOSE)

fclean: clean
	make -f Makefile -C $(DIR_SERVEUR) fclean FGCC=$(FGCC) DEBUG=$(DEBUG)
	make -f Makefile -C $(DIR_CLIENT) fclean FGCC=$(FGCC) DEBUG=$(DEBUG)

re: fclean all

duo: $(NAME) $(CLIENT2)

$(CLIENT2):
	cp $(CLIENT) $(CLIENT2)

.PHONY: all re a clean fclean $(CLIENT) $(SERVEUR)

# Supp rules:
a:
	make re DEBUG=yes
