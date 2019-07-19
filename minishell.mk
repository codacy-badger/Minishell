# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    minishell.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/07/18 20:55:09 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SOURCES_PATH := ./src/

SOURCES :=	main.c \
			transv/error.c \
			input/path.c \
			input/prompt.c \
			input/input.c \
			lex/lexer.c \
			synt/synt.c \
			jcont/jcont.c \
			job/builtins.c \
			job/builtins_dispatcher.c \
			job/job.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

INCLUDES := -I./include/ -I./libft/include/

PATH_LIB = ./libft/

LIB = $(PATH_LIB)libft.a

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

TOOLS_PATH := ./tools/

TESTS_FILE := tests-minishell.txt
