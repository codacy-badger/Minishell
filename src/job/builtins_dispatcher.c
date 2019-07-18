/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dispatcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/17 16:56:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "builtins.h"
#include "error.h"

static const t_builtins	g_builtins[] =
{
	{ "exit", &cmd_exit},
	{ "env", &cmd_env}
};

static void	*dispatcher(char *cmd)
{
	int	i;

	i = 0;
	while (i < 2 && ft_strcmp(cmd, g_builtins[i].key))
	{
		++i;
	}
	if (i == 2)
	{
		return (NULL);
	}
	else
	{
		return ((void*)g_builtins[i].f);
	}
}

int			builtins_select(char **buf)
{
	int			(*f)(char**);
	int			ret;

	ret = e_command_not_found;
	if ((f = dispatcher(*buf)))
	{
		ret = f(buf);
	}
	return (ret);
}
