/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
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

const struct s_opening_tag	g_function_list[] =
{
	{"${", &ft_bracket_expansion, "}"},
	{"$", &ft_dollar_expansion, ""},
	{"\0", NULL, NULL}
};

static int		expansion_dispatcher(char *str)
{
	int	i;

	i = 0;
	while (*(g_function_list[i].opentag))
	{
		if (ft_strstr(str, g_function_list[i].opentag))
			return (i);
		++i;
	}
	return (-1);
}

int			treat_expansions(char **tokens)
{
	int	ref;
	int	i;
	int	ret;

	i = 0;
	if (!tokens)
		return (e_invalid_input);
	while (tokens[i])
	{
		if ((ref = expansion_dispatcher(tokens[i]) != -1))
		{
			if ((ret = g_function_list[ref].function(&tokens[i],
					g_function_list[ref].opentag, g_function_list[ref].closetag)))
				psherror(ret, tokens[i], e_cmd_type);
		/*	ft_printf("after|%s\n", tokens[i]);  check expansion */
		}
		++i;
	}
	return (e_success);
}
