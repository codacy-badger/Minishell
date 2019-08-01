# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    minishell.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/08/01 17:12:53 by abarthel         ###   ########.fr        #
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
			lex/expansion.c \
			synt/synt.c \
			synt/synt_const.c \
			jcont/jcont.c \
			job/builtins_cd.c \
			job/builtins_echo.c \
			job/builtins_env.c \
			job/builtins_exit.c \
			job/builtins_pwd.c \
			job/builtins_dispatcher.c \
			job/builtins_dispatcher.c \
			job/path_concat.c \
			job/job.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

INCLUDES := -I./include/ -I./libft/include/

PATH_LIB = ./libft/

LIB = $(PATH_LIB)libft.a

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

TOOLS_PATH := ./tools/

TESTS_FILE := tests-minishell.txt
