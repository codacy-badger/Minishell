/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:27:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/04 21:08:15 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		ft_printf("%s\n", env[nb]);
		--nb;
	}
	return (env);
}
