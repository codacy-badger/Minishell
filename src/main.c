/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/04 21:46:24 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "env.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	extern char	**environ;
	int			stat;
	int			ret_fork;
	char		*buf;
	char		*pwd;

	if (!environ)
		if (!*environ)
			exit(1);
	environ = env_cpy(environ);
	while (ft_printf("\e[1m\e[96m%s\e[38;5;82m ➠ \e[0m", short_path(&pwd)) && ft_fgetline(STDIN_FILENO, &buf, '\n') >= 0)
	{
		free(pwd);
		/* Built-ins start here: put this in a dispatcher */
		if (!ft_strcmp(buf, "exit"))
		{
			ft_memdel((void**)&buf);
			return (0);
		}
		else if (!ft_strcmp(buf, "env")) // get arg and go to getenv() ft
		{
			ft_print_tables(environ);
			ft_memdel((void**)&buf);
		}
		/* End built-ins*/

		stat = 0;
		if (fork() == 0)
		{
			ret_fork = execve(buf, argv, environ);
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
