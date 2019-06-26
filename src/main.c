/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/26 21:58:40 by abarthel         ###   ########.fr       */
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
	char buf[100];

	ft_bzero((void*)buf, 100);
	while (ft_printf("%s@home ~$ ", getenv("USER")) && read(1, &buf, 100))
	{
		i = 0;
		while (buf[i] != '\n')
			++i;
		if (buf[i] == '\n')
			buf[i] = '\0';
		if (!ft_strcmp(buf, "exit"))
			return (0);
		stat = 0;
		if (fork() == 0)
		{
			return (execve(buf, argv, env));
		}
		else
			wait(&stat);
		ft_bzero((void*)buf, 100);
	}
	return (0);
}
