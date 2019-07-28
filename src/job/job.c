/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/25 21:48:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "builtins.h"
#include "error.h"
#include "libft.h"

static int 	check_type(char *arg)
{
	int		ret;
	struct stat	buf;

	ret = 0;
	if ((ret = stat(arg, &buf)) == -1)
	{
		ft_dprintf(STDERR_FILENO, "'stat' could not find the arg.\n");
		return (ret);
	}
	else if (!ret) 
	{
		ft_printf(">> %d\n", S_ISREG(buf.st_mode));
		ft_printf(">> %d\n", S_ISDIR(buf.st_mode));
		ft_printf(">> %d\n", S_ISCHR(buf.st_mode));
		ft_printf(">> %d\n", S_ISBLK(buf.st_mode));
		ft_printf(">> %d\n", S_ISFIFO(buf.st_mode));
		ft_printf(">> %d\n", S_ISLNK(buf.st_mode));
	}
	/* concat the path and command name to PATH and test it */
	return (ret);
}
/*
static int	check_access(char *arg)
{
	int ret;

	ret = 0;
	if ((ret = access(arg, F_OK)))
	{
		return (ret);
	}
	else if ((ret = access(arg, X_OK)))
	{
		psherror(e_permission_denied, arg);
		return (ret);
	}
	return (0);
}
*/
static int	builtin_keyword_exec(char **argv)
{
	int	ret;

	ret = 0;	
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
/*
static int	process_launch(char **argv, char **envp)
{
	int stat;
	int	ret;

	stat = 0;
	ret = 0;
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
}
*/
int	job(char **argv, char **envp)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!ft_strcmp(argv[0], "builtin")) /* execute builtin if builtin keyword is used */
		return (builtin_keyword_exec(argv));
	ret = check_type(argv[0]); /* check type of the argument */
/*	ret = check_access(argv[0]);
	if (!ret)
	{
		ret = process_launch(argv, envp);
		return (ret);
	}
	else if (ret)
	{
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
	}*/
}
