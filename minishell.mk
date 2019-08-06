# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    minishell.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/08/01 17:23:09 by abarthel         ###   ########.fr        #
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
			lex/expansions/expansions.c \
			lex/expansions/expansion_utils.c \
			lex/expansions/bracket_expansion.c \
			synt/synt.c \
			synt/synt_const.c \
			jcont/jcont.c \
			job/job.c \
			job/path_concat.c \
			job/builtins/builtins_cd.c \
			job/builtins/builtins_echo.c \
			job/builtins/builtins_env.c \
			job/builtins/builtins_exit.c \
			job/builtins/builtins_pwd.c \
			job/builtins/builtins_dispatcher.c \
			job/builtins/builtins_dispatcher.c \

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

INCLUDES := -I./include/ -I./libft/include/

PATH_LIB = ./libft/

LIB = $(PATH_LIB)libft.a

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

TESTS_PATH := ./tools/tests/

TESTS_SCRIPT := launch_test.sh "launch from makefile"
