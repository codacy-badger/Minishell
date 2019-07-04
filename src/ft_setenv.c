/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:49:03 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/04 21:11:50 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env.h"

static char	**getenvvar(const char *name)
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
				return (&environ[i]);
			}
		}
	}
	return (NULL);
}

int				ft_setenv(const char *name, const char *value, int overwrite)
{
	char		**env_var;
	char		*tmp;
	size_t		len;

	if (overwrite)
	{
		len = ft_strlen(value) + ft_strlen(name) + 2;
		if ((env_var = getenvvar(name)))
		{
			free(*env_var);
			*env_var = ft_memalloc(len);
			tmp = ft_strendcpy(*env_var, name);
			tmp = ft_strendcpy(tmp, "=");
			tmp = ft_strendcpy(tmp, value);
		}
		else
		{
		/* add new var */	

		}
		return (0);
	}
	else
		return (-1);
}
