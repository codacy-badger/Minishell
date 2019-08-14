/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 12:43:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.unix.com/man-page/posix/1posix/cd/
*/

#include <unistd.h>

#include "libft.h"
#include "error.h"

static int	refresh_pwd(void)
{
	char	*cwd;

	if (!(cwd = getcwd(NULL, 0)))
		return (e_system_call_error);
	if (ft_setenv("PWD", cwd, 1))
		return (e_cannot_allocate_memory);
	ft_memdel((void**)&cwd);
	return (0);
}

int		cmd_cd(int argc, char **argv)
{
	int	ret;

	(void)argc;
	/* options are to be parsed */
	ret = e_success;
	if (chdir(argv[1]))
	{
		psherror(e_system_call_error, argv[0], e_cmd_type);
		return (g_errordesc[e_system_call_error].code);
	}
	if ((ret = refresh_pwd()))
	{
		psherror(ret, argv[0], e_cmd_type);
		return (g_errordesc[ret].code);
	}
	return (ret);
}
