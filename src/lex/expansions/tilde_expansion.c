/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:07:44 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 18:48:23 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "expansions.h"

int	ft_tilde_expansion(char **str)
{
	char	*env;
	char	*cpy;
	char	*start;

	start = &(*str)[1];
	if (!(*str)[1] || (*str)[1] == '/')
	{
		if (!(env = ft_getenv("HOME")))
			return (e_success);
	}
	else if ((*str)[1] == '-' && ((*str)[2] == '/' || !(*str)[2]))
	{
		if (!(env = ft_getenv("OLDPWD")))
			return (e_success);
		start = &(*str)[2];

	}
	else if ((*str)[1] == '+' && ((*str)[2] == '/' || !(*str)[2]))
	{
		if (!(env = ft_getenv("PWD")))
			return (e_success);
		start = &(*str)[2];
	}
	/* does not handle proper chr */
	ft_printf("|%s|\n", start);
	cpy = ft_strjoin(env, start);
	ft_memdel((void**)str);
	*str = cpy;
	ft_printf(">%s\n", cpy);
	return (e_success);
}
