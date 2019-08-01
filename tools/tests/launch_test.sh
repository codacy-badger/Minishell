#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    launch_test.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 10:05:56 by abarthel          #+#    #+#              #
#    Updated: 2019/08/01 10:05:56 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINISHELL_PATH='../../'
tests_array=(*.test)

make -j -C $MINISHELL_PATH

for file in "${tests_array[@]}"
do
	printf "\n\n\e[4m\e[92m"$file"\e[0m\n"
	$MINISHELL_PATH./minishell < $file
done

make fclean -C $MINISHELL_PATH
