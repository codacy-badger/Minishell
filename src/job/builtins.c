/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 17:47:58 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	cmd_exit(char **argv)
{
	extern char **environ;

	ft_tabdel(&argv);
	ft_tabdel(&environ);
	exit(0);
}

int	cmd_env(char **argv)
{
	extern char **environ;

	(void)argv;
	ft_print_tables(environ);
	return (0);
}

int	cmd_cd(char **argv)
{

	(void)argv;
	return (0);
}

int	cmd_echo(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i + 1])
		{
			ft_printf("%s ", argv[i]);
		}
		else
		{
			ft_printf("%s\n", argv[i]);
		}
		++i;
	}
	return (0);
}

int	cmd_pwd(char **argv)
{
	char	*cwd;

	(void)argv;
	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		return (1);
	}
	else
	{
		ft_printf("%s\n", cwd);
		ft_memdel((void**)&cwd);
	}
	return (0);
}
