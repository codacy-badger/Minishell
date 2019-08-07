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

static int	replace_tilde(char **str, char *start, char *env)
{
	char	*cpy;
	
	if (!env)
		return (e_success);
	if (!(cpy = ft_strjoin(env, start)))
		return (e_cannot_allocate_memory);
	ft_memdel((void**)str);
	*str = cpy;
	return (e_success);
}

size_t		tilde_expansion(char **str, const char *opentag, const char *closetag)
{
	char	*env;
	int	ret;

	(void)opentag;
	(void)closetag;
	if (!(*str)[1] || (*str)[1] == '/')
	{
		env = ft_getenv("HOME");
		ret = replace_tilde(str, &(*str)[1], env);
		return (ret);
	}
	else if ((*str)[1] == '-' && ((*str)[2] == '/' || !(*str)[2]))
	{
		env = ft_getenv("OLDPWD");
		ret = replace_tilde(str, &(*str)[2], env);
		return (ret);
	}
	else if ((*str)[1] == '+' && ((*str)[2] == '/' || !(*str)[2]))
	{
		env = ft_getenv("PWD");
		ret = replace_tilde(str, &(*str)[2], env);
		return (ret);
	}
	return (e_success);
}
