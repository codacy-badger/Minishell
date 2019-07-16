/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/16 13:49:30 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

/*
 ** Physical Module "job" handles the execution of commands
 ** Thereby, it checks if access to the cmd is possible, access(), builtins and
 ** then fork it or return an error msg.
 ** On call of the module execute one command with its options.
 ** to call the module -> job(char** argv, char **env), it returns the return
 ** value of the execute command. In case command is not found it returns the
 ** value defined by the enum. e.g "command not found = 127"
 */


int	job(char **argv, char **envp)
{
	ft_print_tables(argv);
	ft_print_tables(envp);
	return (0);
}
/* {
	int		ret;

	ret = 0;
	if ((ret = builtins_select(argv)) != e_command_not_found)
	{
		continue ;
	}
	else if (fork() == 0)
	{
		if (access(argv[0], 1000))
		{
			ft_dprintf(STDERR_FILENO, "%s: command not found: %s\n", "Minishell", argv[0]);
			ft_tabdel(&envp);
			ft_memdel((void**)argv);
			exit (e_command_not_found);
		}
		ret = execve(bin, argv, envp);
		ft_memdel((void**)argv);
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
		ft_memdel((void**)&buf);
	}
} */
