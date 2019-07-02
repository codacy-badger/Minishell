/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:54:14 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/02 20:25:04 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_getenv(const char *name)
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
			if (environ[i][j] != '=')
				++i;
			else
			{
				++j;
				return (&environ[i][j]);
			}
		}
	}
	return (NULL);
}
