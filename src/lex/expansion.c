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

#include "libft.h"
#include "error.h"
#include "expansion.h"

static char	*expansion_loc(char *str)
{
	int					i;
	char				*loc;
	struct s_expan_tags	tags[] =
	{ {"${"}, {"$"}, {"\0"} };

	i = 0;
	while (*(tags[i].expansion_tag))
	{
		if ((loc = ft_strstr(str, "$")))
			return (loc);
		++i;
	}
	return (NULL);
}

int			treat_expansions(char **tokens)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!tokens)
		return (e_invalid_input);
	while (tokens[i])
	{
		ptr = expansion_loc(tokens[i]);
		ft_printf(">>%s\n", ptr);
		tokens[i] = ft_strrep(&tokens[i], ft_getenv("LOGNAME"), "$LOGNAME");
		ft_printf("|%s\n", tokens[i]);
		++i;
	}
	return (e_success);
}
