/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/06 21:15:32 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"
#include "error.h"

int	main(void)
{
	extern char	**environ;
	int			stat;
	int			ret_fork;
	char		*buf;
	char		**argv;

	environ = ft_envcpy(environ);
	stat = 0;
	argv = NULL;
	while (prompt_display(WEXITSTATUS(stat)) && ft_fgetline(STDIN_FILENO, &buf, '\n') >= 0)
	{
		stat = 0;
		if (builtins_select(&buf))
			continue ;
		else if (fork() == 0)
		{
			if (access(buf, 1000))
			{
				ft_dprintf(STDERR_FILENO, "%s: command not found: %s\n", argv[0], buf);
				exit (127);
			}
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
