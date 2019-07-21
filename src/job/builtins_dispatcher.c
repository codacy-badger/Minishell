/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dispatcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 13:19:13 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "builtins.h"
#include "error.h"

static const t_builtins	g_builtins[] =
{
	{ "echo", &cmd_echo},
	{ "exit", &cmd_exit},
	{ "env", &cmd_env},
	{ "cd", &cmd_cd},
	{ "\0", NULL}
};

static void	*dispatcher(char *cmd)
{
	int	i;

	i = 0;
	while (g_builtins[i].key[0] && ft_strcmp(cmd, g_builtins[i].key))
	{
		++i;
	}
	if (!(g_builtins[i].key[0]))
	{
		return (NULL);
	}
	else
	{
		return ((void*)g_builtins[i].f);
	}
}

int			builtins_select(char **argv)
{
	int			(*f)(char**);
	int			ret;

	ret = e_command_not_found;
	if ((f = dispatcher(*argv)))
	{
		ret = f(argv);
	}
	return (ret);
}
