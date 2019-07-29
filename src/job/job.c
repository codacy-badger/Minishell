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
#include "job.h"

static int 	check_type(char **arg)
{
	struct stat	buf;
	char		*cmd;
	int		ret;
	_Bool		more_path;

	buf = (struct stat){.st_mode = 0};
	cmd = *arg;
	ret = e_success;
	more_path = 1;
	while ((ret = stat(*arg, &buf)) && more_path)
		*arg = ft_concat_path(cmd, &more_path);
	if (S_ISDIR(buf.st_mode)) 
		return (e_is_a_directory);
	else if (ret && *cmd == '/')
		return (e_no_such_file_or_directory);
	else if (ret)
		return (e_command_not_found);
	else
		return (e_success);
}

static int	check_access(char *arg)
{
	int ret;

	ret = e_success;
	if ((ret = access(arg, X_OK)))
	{
		psherror(e_permission_denied, arg, e_cmd_type);
		return (e_permission_denied);
	}
	return (e_success);
}

static int	builtin_keyword_exec(char **argv)
{
	int	ret;

	ret = e_success;
	if (argv[1] && (ret = builtins_dispatcher(&argv[1])) != e_command_not_found)
	{
		return (ret);
	}
	else
	{
		psherror(e_no_builtin, argv[1], e_cmd_type);
		return (g_errordesc[e_no_builtin].code);
	}
}

static int	process_launch(char **argv, char **envp, char *cmd)
{
	int	stat;
	int	ret;

	stat = 0;
	ret = e_success;
	ft_swap((void**)&argv[0], (void**)&cmd);
	if (fork() == 0) /*add fork protection, check SHLVL and resources */
	{
		ret = execve(cmd, argv, envp);
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
	int	ret;
	char	*cmd;

	ret = e_success;
	if (!ft_strcmp(argv[0], "builtin"))
		return (builtin_keyword_exec(argv));
	cmd = argv[0];
	if ((ret = check_type(&argv[0])) != e_command_not_found && ret != e_success) /* check type of the argument */
	{
		psherror(ret, cmd, e_cmd_type);
		return (g_errordesc[ret].code);
	}
	if (ret == e_success)
	{
		if (!check_access(argv[0]))
			return (process_launch(argv, envp, cmd));
		else
			return (g_errordesc[e_permission_denied].code);
	}
	else /* behave like it is a builtin */
	{
		ret = builtins_dispatcher(&argv[0]);
	   	if (ret == e_command_not_found)
		{
			psherror(e_command_not_found, argv[0], e_cmd_type);
			return (g_errordesc[e_command_not_found].code);
		}
		return (ret);
	}
}
