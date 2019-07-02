/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/02 18:27:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "env.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	int		stat;
	int		ret_fork;
	char	*buf;

	if (!env)
		if (!*env)
			exit(1);
	ft_getenv("LOGNAME");
//	ft_printf("%s\n", ft_getenv("LOGNAME")); /* Tests ft_getenv */
	while (write(STDOUT_FILENO, "$> ", 3) && ft_fgetline(STDIN_FILENO, &buf, '\n') >= 0)
	{
		/* Built-ins start here: put this in a dispatcher */
		if (!ft_strcmp(buf, "exit"))
		{
			ft_memdel((void**)&buf);
			return (0);
		}
		else if (!ft_strcmp(buf, "env")) // get arg and go to getenv() ft
		{
			ft_print_tables(env);
			ft_memdel((void**)&buf);
		}
		/* End built-ins*/

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
