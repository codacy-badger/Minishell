/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/17 16:49:19 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "builtins.h"
#include "error.h"
#include "libft.h"
#include <errno.h>
#include "ft_errno.h"
#include <stdio.h>
#include <sys/wait.h>

/*
 ** Module "job" handles the execution of commands
 ** Thereby, it checks if access to the cmd is possible, access(), builtins and
 ** then fork it or return an error msg.
 ** On call of the module execute one command with its options.
 ** to call the module -> job(char** argv, char **envip), it returns the return
 ** value of the execute command. In case command is not found it returns the
 ** value defined by the enum. e.g "command not found = 127"
 */

/*
 *
 *
 * F_OK
 *     Tests whether the file exists.
 * R_OK
 *     Tests whether the file can be accessed for reading.
 * W_OK
 *     Tests whether the file can be accessed for writing.
 * X_OK
 *     Tests whether the file can be accessed for executio
*/

static int	check_access(char *arg)
{
	if (access(arg, F_OK) == -1)
	{
		ft_printf("path1,2...\n");
	/* concat the path and command name to PATH and test it */
	}
	else if (access(arg, X_OK))
	{
		g_errno = E_EACCES;
		ft_perror(NULL);
	}
	else
		return (0);
	return (1);
}

int	job(char **argv, char **envp)
{
	int		ret;
	int		stat;

	ret = 0;
	stat = 0;
	if ((ret = builtins_select(&argv[0])) != e_command_not_found)
	{
		return (ret);
	}
	else if (fork() == 0)
	{
		if (!check_access(argv[0]))
		{
			ft_dprintf(STDERR_FILENO, "%s: command not found: %s\n", "Minishell", argv[0]);
			ft_tabdel(&envp);
			ft_tabdel(&argv);
			exit (e_command_not_found);
		}
		ret = execve(argv[0], argv, envp);
		ft_tabdel(&argv);
		ft_tabdel(&envp);
		exit (ret);
	}
	else
	{
		wait(&stat);
		ret = WEXITSTATUS(stat);
		if (ret)
		{
			ft_printf("%d\n", ret);
		}
		ft_memdel((void**)argv[0]);
		return (ret);
	}
}
