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

const struct s_tags	g_tags[] =
{
	{"${", "}"},
	{"$", ""},
	{"\0", NULL}
};

static int		expansion_dispatcher(char *str)
{
	int	i;

	i = 0;
	while (*(g_tags[i].opentag))
	{
		if (ft_strstr(str, g_tags[i].opentag))
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
		ref = expansion_dispatcher(tokens[i]);
		if (ref != -1)
			if ((ret = ft_replace_expansion(&tokens[i], g_tags[ref].opentag, g_tags[ref].closetag)))
				psherror(ret, tokens[i], e_cmd_type);
		++i;
	}
	return (e_success);
}
