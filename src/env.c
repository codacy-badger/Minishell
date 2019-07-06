/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:27:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/06 14:53:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

char	**env_cpy(char **envp)
{
	char	**env;
	int		nb;

	env = NULL;
	nb = 0;
	while (envp[nb])
	{
		++nb;
	}
	env = (char**)ft_memalloc(sizeof(char**) * (nb + 1));
	--nb;
	while (nb >= 0)
	{
		env[nb] = ft_strdup(envp[nb]);
		--nb;
	}
	return (env);
}

char	*short_path(char **cwd)
{
	int		i;

	i = 0;
	*cwd = getcwd(NULL, 0);
	while ((*cwd)[i])
		++i;
	if (i > 0)
		--i;
	while ((*cwd)[i] != '/')
		--i;
	++i;
	return (&(*cwd)[i]);
}
