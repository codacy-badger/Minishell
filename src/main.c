/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/20 19:48:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	int stat;
	int i;
	char buf[10000];

	ft_bzero((void*)buf, 10000);
	while (ft_printf("%s@home ~$ ", getenv("USER")) && read(1, &buf, 10000))
	{
		stat = 0;
		if (fork() == 0)
		{
			i = 0;
			while (buf[i] != '\n')
				++i;
			if (buf[i] == '\n')
				buf[i] = '\0';
			execve(buf, argv, env);
		}
		else
		{
			wait(&stat);
			ft_bzero((void*)buf, 10000);
		}
	}
	return (0);
}
