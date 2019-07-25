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

static int	check_access(char *arg)
{
	int ret;
	struct stat buf;

	if (lstat(arg, &buf) != -1)
	{
		if (buf)
		/* code generic function that return the type of the arg using lstat or fstat or stat*/
	}
	else if ((ret = access(arg, F_OK)))
	{
		return (ret);
	/* concat the path and command name to PATH and test it */
	}
	else if ((ret = access(arg, X_OK)))
	{
		psherror(e_permission_denied, arg);
		return (ret);
	}
	return (0);
}

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

int	job(char **argv, char **envp)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (!ft_strcmp(argv[0], "builtin")) /* execute builtin if builtin keyword is used */
		return (builtin_keyword_exec(argv));
	else if (!(ret = check_access(argv[0])))
	{
		ret = process_launch(argv, envp);
		ft_printf("ret:%d\n", ret);
		perror(NULL);
		return (ret);
		/*return (g_errordesc[ret].code);
*/	}
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
