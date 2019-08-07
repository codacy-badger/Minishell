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
	{"${", &ft_replace_expansion, "}"},
	{"$", &ft_replace_expansion, ""},
	{"~", &ft_tilde_expansion, ""},
	{"\0", NULL, NULL}
};

static int	expansion_dispatcher(char *str)
{
	int	i;
	int	ref;
	char	*ptr;
	char	*closest;

	i = 0;
	closest = NULL;
	ref = -1;
	while (*(g_tags[i].opentag))
	{
		ptr = ft_strstr(str, g_tags[i].opentag);
		if (ptr && (!closest || (ptr < closest && closest)))
		{
			closest = ptr;
			ref = i;
		}
		++i;
	}
	return (ref);
}

static char	*get_closest_exp(char *str)
{
	int	i;
	char	*ptr;
	char	*closest;

	i = 0;
	closest = NULL;
	while (*(g_tags[i].opentag))
	{
		ptr = ft_strstr(str, g_tags[i].opentag);
		if (ptr && (!closest || (ptr < closest && closest)))
			closest = ptr;
		++i;
	}
	return (closest);
}

int			treat_expansions(char **tokens)
{
	int	ref;
	int	i;
	int	ret;
	char	*next;

	i = 0;
	if (!tokens)
		return (e_invalid_input);
	while (tokens[i])
	{
		next = tokens[i];
		while ((next = get_closest_exp(next)))
		{
			ft_printf("next |%s\n", next);
			ref = expansion_dispatcher(next);
			ft_printf("ref:%d\n", ref);
			if ((ret = g_tags[ref].f(&tokens[i], g_tags[ref].opentag, g_tags[ref].closetag)))
				psherror(ret, tokens[i], e_cmd_type);
			++next;
		}

		/*
		if (*(tokens[i]) == '~')
		{
			if ((ret = ft_tilde_expansion(&tokens[i])))
				psherror(ret, tokens[i], e_cmd_type);
		}
		ref = expansion_dispatcher(tokens[i]);
		if (ref != -1)
			if ((ret = ft_replace_expansion(&tokens[i], g_tags[ref].opentag, g_tags[ref].closetag)))
				psherror(ret, tokens[i], e_cmd_type);
		*/
		++i;
	}
	return (e_success);
}
