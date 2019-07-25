/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/25 20:39:07 by abarthel         ###   ########.fr       */
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
		return (e_command_not_found);
	/* concat the path and command name to PATH and test it */
	}
	else if (access(arg, X_OK))
	{
		psherror(e_permission_denied, arg);
		return (e_permission_denied);
	}
	else
	{
		return (0);
	}
}

static int	builtin_keyword_exec(char **argv)
{
	int ret;
	
	if (argv[1] && (ret = builtins_select(&argv[1])) != e_command_not_found)
	{
		return (ret);
	}
	else
	{
		psherror(e_no_builtin, argv[1]);
		return (g_errordesc[e_no_builtin].code);
	}
}

int	job(char **argv, char **envp)
{
	int		ret;
	int		stat;
	int		i;

	i = 0;
	ret = 0;
	stat = 0;
	if (!ft_strcmp(argv[0], "builtin")) /* execute builtin if builtin keyword is used */
		return (builtin_keyword_exec(argv));
	else if (!(ret = check_access(argv[0])))
	{
		if (fork() == 0)
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
		return (g_errordesc[ret].code);
	}
	else
	{
		ret = builtins_select(&argv[i]);
	   	if (ret == e_command_not_found)
		{
			psherror(e_command_not_found, argv[i]);
			return (g_errordesc[e_command_not_found].code);
		}
		return (ret);
	}
}
