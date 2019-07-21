/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 12:22:49 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
	extern char	**environ;

	(void)argv;
	(void)environ;
	return (0);
}
