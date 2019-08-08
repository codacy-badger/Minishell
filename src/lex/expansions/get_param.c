/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
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
#include "jcont.h"

static char	*getretval(const char *str)
{
	(void)str;
	ft_bzero((void*)g_alret, sizeof(g_alret));
	/* itoa without malloc, that writes on buffer */
	g_alret[0] = '1';
	g_alret[1] = '2';
	g_alret[2] = '3';
	return (g_alret);
}

const struct s_param	g_param[] =
{
	{"?", &getretval},
/*	{"$", &ft_getenv},
	{"@", &ft_getenv},
*/	{"", &ft_getenv}
};

static int	parameter_dispacther(char **content, const char *str)
{
	int	i;

	i = 0;
	while (*(g_param[i].pname))
	{
		if (!ft_strcmp(g_param[i].pname, str))
			break;
		++i;
	}
	if (!*(g_param[i].pname))
	{
		if (is_valid_param(str))
		{
			*content = NULL;
			return (e_bad_substitution);
		}
	}
	*content = g_param[i].g(str);
	return (e_success);
}

int	getenv_content(char **content, char *str, const char *closetag)
{
	size_t	len;
	int	ret;
	char	c;

	ret = e_success;
	len = ft_varlen(str, closetag);
	if (!len)
		return (e_bad_substitution);
	c = str[len];
	str[len] = '\0';
	ret = parameter_dispacther(content, str);
	str[len] = c;
	return (ret);
}
