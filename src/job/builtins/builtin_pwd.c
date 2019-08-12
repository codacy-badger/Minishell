/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 20:16:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	cmd_pwd(int argc, char **argv)
{
	char	*cwd;

	/*if (argv[1] && !ft_strcmp(argv[1], "-L"))
	{
	}*/
	(void)argc;
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
