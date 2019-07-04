/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:49:03 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/04 18:29:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env.h"

static char	*getenvvar(const char *name)
{
	extern char **environ;
	int			i;
	int			j;

	if (!name)
		ft_print_tables(environ);
	else
	{
		i = 0;
		while (environ[i])
		{
			j = 0;
			while (name[j] && environ[i][j] && name[j] == environ[i][j])
				++j;
			if (environ[i][j] != '=' || name[j])
				++i;
			else
			{
				++j;
				return (environ[i]);
			}
		}
	}
	return (NULL);
}

int				ft_setenv(const char *name, const char *value, int overwrite)
{
	extern char	**g_env;
	char		*env_name;
	char		*tmp;
	size_t		len;

	env_name = NULL;
	if (overwrite)
	{
		/* Set arg */
		if ((env_name = ft_getenv(name)))
		{
			len = ft_strlen(value);
			if (len <= ft_strlen(env_name))
			{
				ft_strcpy(env_name, value);
			}
			else
			{
			//	ft_printf("L");
				env_name = getenvvar(name);
			//	ft_printf("|%s|\n", environ[getenvvar(name)]);
		//		ft_printf("|%s,", env_name);
			//	free(environ);
			//	environ[16] = ft_memalloc(ft_strlen(name) + ft_strlen(value) + 2); /* 2 correspond to '=' and '\0' */
				tmp = ft_strcpy(env_name, "welkfjwalekfjwefwefew");
				tmp = ft_strcpy(tmp, "=");
				tmp = ft_strcpy(tmp, value);
				ft_printf("|%s,", env_name);
			}
		}
		return (0);
	}
	else
	{
		return (-1);
	}
}
