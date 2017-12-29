# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdenion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/13 09:07:37 by tdenion           #+#    #+#              #
#    Updated: 2016/11/07 05:32:03 by tdenion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### General var ###

CC= gcc
FLAGS= -Werror -Wextra -Wall

### Name ###

NAME= lem-in

### libft ###

LIBFT= lib/libft.a

### Srcs ###

FILES= lem_in.c check.c lst_crt.c tool.c build_roads.c build_node.c \
	   lst_destroy.c process.c print.c tool_lst.c fms.c \

SRCS= $(addprefix $(SRC_PATH)/, $(FILES))


### Objects ###

OBJS= $(SRCS:.c=.o)

### Path ###

SRC_PATH= srcs
INCLUDE= -I include -I lib/includes

### Colors ###

RESET=\033[0m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m

### Rules ###

all:$(NAME)

$(NAME):$(OBJS)
	@make -C lib
	@echo "$(GREEN)Compilation $(YELLOW)de $(RED)$@$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ $^ $(LIBFT)

%.o:%.c
	@echo "$(GREEN)Compilation $(YELLOW)de $(RED)$@$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@make -C lib clean
	@echo "$(GREEN)Suppression $(YELLOW)des $(RED)objets$(RESET)"
	@rm -f $(OBJS)

aclean:
	@rm -f $(OBJS)

fclean: aclean
	@make -C lib fclean
	@echo "$(GREEN)Suppression $(YELLOW)de $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean aclean fclean re test leaks

test:all
	./$(NAME) < map2

leaks:all
	valgrind --leak-check=full ./$(NAME) < map2

