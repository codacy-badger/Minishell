/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 19:17:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "builtins.h"
#include "error.h"
#include "libft.h"

static int	check_access(char *arg)
{
	if (access(arg, F_OK) == -1)
	{
		if (0 == 0)
			return (0);
		else
			return (check_access(arg));
	/* concat the path and command name to PATH and test it */
	}
	else if (access(arg, X_OK))
	{
		psherror(e_permission_denied, arg);
	}
	else
		return (0);
	return (1);
}

int	job(char **argv, char **envp)
{
	int		ret;
	int		stat;
	int		i;
	/*char	*path;*/

	i = 0;
	ret = 0;
	stat = 0;
	if (!ft_strcmp(argv[0], "builtin"))
	{
		++i;
		if (argv[i] && (ret = builtins_select(&argv[i])) != e_command_not_found)
		{
			return (ret);
		}
		else
		{
			psherror(e_no_builtin, argv[i]);
			return (g_errordesc[e_no_builtin].code);
		}
	}
	if ((ret = builtins_select(&argv[i])) != e_command_not_found)
	{
		return (ret);
	}
	else if (check_access(argv[0]) == 1)
	{
		return (g_errordesc[e_command_not_found].code);
	}
	else if (fork() == 0)
	{
		ret = execve(argv[0], argv, envp);
		ft_tabdel(&argv);
		ft_tabdel(&envp);
		exit (ret);
	}
	else
	{
		wait(&stat);
		ret = WEXITSTATUS(stat);
		return (ret);
	}
}
