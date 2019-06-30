/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/30 17:07:12 by abarthel         ###   ########.fr       */
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
	int		stat;
	int		ret_fork;
	char	*buf;

	while (ft_printf("%s@home ~$ ", getenv("USER")) && ft_fgetline(STDIN_FILENO, &buf, '\n') >= 0)
	{
		if (!ft_strcmp(buf, "exit"))
		{
			ft_memdel((void**)&buf);
			return (0);
		}
		stat = 0;
		if (fork() == 0)
		{
			ret_fork = execve(buf, argv, env);
			ft_memdel((void**)&buf);
			return (ret_fork);
		}
		else
		{
			wait(&stat);
			ft_memdel((void**)&buf);
		}
	}
	return (0);
}
