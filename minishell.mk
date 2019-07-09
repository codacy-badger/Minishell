# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    minishell.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/07/09 12:02:37 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES_PATH := ./src/

SOURCES :=	main.c \
			error.c \
			path.c \
			prompt.c \
			builtins.c \
			builtins_dispatcher.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

INCLUDES := -I./include/ -I./libft/include/

PATH_LIB = ./libft/

LIB = $(PATH_LIB)libft.a

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))
