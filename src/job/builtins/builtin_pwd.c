/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/21 14:29:48 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

int	cmd_pwd(int argc, char **argv)
{
	char	*cwd;

	(void)argc;
	(void)argv;
	/* should use getopt -L -P etc */
	if ((cwd = ft_getenv("PWD")))
		ft_printf("%s\n", cwd);
	else
	{
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
	}
	return (0);
}
