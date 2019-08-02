/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
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
#include "expansion.h"

static int	ft_simple_expansion(char **str)
{
	(void)str;
	
	
	*str = ft_strrep(str, ft_getenv("LOGNAME"), "$LOGNAME");
	return (e_success);
}

const struct s_opening_tag	g_function_list[] =
{
	{"${", NULL},
	{"$", &ft_simple_expansion},
	{"\0", NULL}
};

static void		*expansion_dispatcher(char *str)
{
	int	i;

	i = 0;
	while (*(g_function_list[i].tag))
	{
		if (ft_strstr(str, g_function_list[i].tag))
			return (g_function_list[i].function);
		++i;
	}
	return (NULL);
}

int			treat_expansions(char **tokens)
{
	char	*(*function)(char*);
	int		i;
	int		ret;

	i = 0;
	if (!tokens)
		return (e_invalid_input);
	while (tokens[i])
	{
		if ((function = expansion_dispatcher(tokens[i])))
		{
			if ((ret = ft_simple_expansion(&tokens[i])))
				psherror(ret, tokens[i], e_cmd_type);
			ft_printf("after|%s\n", tokens[i]); /* check expansion */
		}
		++i;
	}
	return (e_success);
}
