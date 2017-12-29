# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdenion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 15:16:14 by tdenion           #+#    #+#              #
#    Updated: 2016/11/07 06:33:22 by tdenion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Basic variable ----#

CC= gcc
FLAGS= -Werror -Wextra -Wall
AR= ar rc
NAME= libft.a

#---- Sources ----#

FILES_LIBFT= ft_putstr.c ft_putstr_fd.c ft_putchar.c \
	ft_putchar_fd.c ft_bzero.c ft_memset.c \
	ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_strcpy.c ft_strncpy.c \
	ft_strlen.c ft_tolower.c ft_charcmp.c \
	ft_memcpy.c ft_strdup.c ft_toupper.c \
	ft_strncmp.c ft_strcmp.c ft_memcpy.c \
	ft_memccpy.c ft_memcmp.c ft_memmove.c \
	ft_memchr.c ft_atoi.c ft_isprint.c \
	ft_isalpha.c ft_isdigit.c ft_isascii.c \
	ft_isalnum.c ft_strcat.c ft_strchr.c \
	ft_strlcat.c ft_strncat.c ft_strnstr.c \
	ft_strrchr.c ft_strstr.c ft_strncat.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c \
	ft_strdel.c ft_strclr.c ft_strequ.c \
	ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_strrev.c \
	ft_itoa.c ft_strsncpy.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_lstnew.c ft_lstadd.c ft_lstdelone.c \
	ft_strfjoin.c ft_lstdel.c ft_lstiter.c \
	ft_lstmap.c ft_strlen_bc.c ft_cword_bc.c \
	ft_nbrlen.c \

FILES_GNL= get_next_line.c \

FILES_PRINTF= conversion.c flags.c ft_printf.c len_modif.c lst.c precision.c \
			print.c print_char.c print_hex.c print_nbr.c print_prec.c \
			print_wchar.c tool.c tool_wchar.c \

SRCS= $(addprefix $(SRCPATH_LIBFT)/, $(FILES_LIBFT)) \
	  $(addprefix $(SRCPATH_GNL)/, $(FILES_GNL)) \
	  $(addprefix $(SRCPATH_PRINTF)/, $(FILES_PRINTF))\

#---- Objects ----#

OBJS= $(SRCS:.c=.o)

#---- Path ----#

SRCPATH_LIBFT= libft
SRCPATH_GNL= get_next_line
SRCPATH_PRINTF= ft_printf
INCLUDE= -I includes
SRC_PATH= libft \
		  get_next_line \
		  ft_printf \

#---- Colors ----#

RESET=\033[0m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m

#---- Rules ----#

all:$(NAME)

$(NAME):$(OBJS)
	@echo "$(GREEN)Creation $(YELLOW)de $(RED)$@$(RESET)"
	@$(AR) $@ $^
	@ranlib $@

%.o:%.c
	@echo "$(GREEN)Creation $(YELLOW)de $(RED)$@$(RESET)"
	@$(CC) $(FLAGS) -o $@ -c $^

clean:
	@echo "$(GREEN)Suppression $(YELLOW)des $(RED)objets$(RESET)"
	@rm -f $(OBJS)

fclean:clean 
	@echo "$(GREEN)Suppression $(YELLOW)de $(RED)$(NAME)$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean
