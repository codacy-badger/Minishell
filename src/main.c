/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/06 19:01:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"
#include "error.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	extern char	**environ;
	int			stat;
	int			ret_fork;
	char		*buf;

	environ = ft_envcpy(environ);
	stat = 0;
	while (prompt_display(WEXITSTATUS(stat)) && ft_fgetline(STDIN_FILENO, &buf, '\n') >= 0)
	{
		stat = 0;
		/* Built-ins start here: put this in a dispatcher */
		if (!ft_strcmp(buf, "exit"))
		{
			ft_memdel((void**)&buf);
			return (0);
		}
		else if (!ft_strcmp(buf, "env")) /* get arg and go to getenv() ft */
		{
			ft_print_tables(environ);
			ft_memdel((void**)&buf);
		}
		/* End built-ins*/

		else if (fork() == 0)
		{
			ret_fork = execve(buf, argv, environ);
			ft_memdel((void**)&buf);
			ft_tabdel(&environ);
			exit (ret_fork);
		}
		else
		{
			wait(&stat);
			ft_memdel((void**)&buf);
		}
	}
	ft_tabdel(&environ);
	return (0);
}
