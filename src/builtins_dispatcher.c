/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_dispatcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/11 18:48:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"
#include "error.h"

static const t_builtins	g_builtins[] =
{
	{ "exit", &cmd_exit},
	{ "env", &cmd_env}
};

static int	*dispatcher(char *cmd)
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
		return ((int*)g_builtins[i].f);
	}
}

int			builtins_select(char **buf)
{
	extern char	**environ;
	int			*(*f)(char**);

	if ((f = (int *(*)(char**))dispatcher(*buf)))
	{
		return ((int)f(buf));
	}
	else
	{
		/*write(STDOUT_FILENO, , ft_strlen());
	*/	return (e_command_not_found);
	}
}
