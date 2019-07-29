# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:03:51 by abarthel          #+#    #+#              #
#    Updated: 2019/07/15 17:06:45 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include minishell.mk

SANITIZE := -fsanitize=address
#SANITIZE :=

#OPTIMIZATION := -O2 -fno-builtin
OPTIMIZATION :=

DEBUGGING := -g

WARNING := -Wall -Wextra -Werror

ANSI := -ansi

.PHONY: all clean fclean re

all: $(NAME)

$(NAME)	: $(OBJECTS)
	@make lib -j -C $(PATH_LIB)
	@$(CC) $(WARNING) $(CFLAGS) $(DEBUGGING) $(SANITIZE) $^ -o $@ $(LIB)
	@printf "\n\e[38;5;44m%4s [\e[1m$(NAME) built]\n\n\e[0m"

clean:
	@$(RM) $(OBJECTS) $(DEPENDS)
	@make clean -C $(PATH_LIB)

fclean:
	@$(RM) $(OBJECTS) $(DEPENDS) $(NAME)
	@make fclean -C $(PATH_LIB)

re: fclean $(NAME)

test: all
	@./$(NAME) < $(TOOLS_PATH)$(TESTS_FILE)

-include $(DEPENDS)

%.o: %.c Makefile
	@$(CC) $(WARNING) $(CFLAGS) $(DEBUGGING) $(ANSI) $(SANITIZE) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "\e[38;5;155m%-20s \e[38;5;37mobject built\n\e[0m" $(notdir $(basename $@))
