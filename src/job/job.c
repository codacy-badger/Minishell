/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 13:23:06 by abarthel         ###   ########.fr       */
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
	/*char	*path;*/

	ret = 0;
	stat = 0;
	if ((ret = builtins_select(argv)) != e_command_not_found)
	{
		return (ret);
	}
	else if (check_access(argv[0]) == 1)
	{
		return (e_permission_denied);
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
