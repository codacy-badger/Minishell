/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unglue_sep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:59:39 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 17:14:33 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "separators.h"

const struct s_separators	g_separators[] =
{
	{";"},
	{"\0"}
};
/*
static _Bool	isseparator(char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	while ((len = ft_strlen(g_separators[i].sep))
			&& ft_strncmp(g_separators[i].sep, s, len))
	{
		ft_printf("-|%s\n", s);
		++i;
	}
	if (!len)
		return (0);
	else
		return (1);
}
*/
static char	*get_closest_sep(char *str)
{
	int	i;
	char	*ptr;
	char	*closest;

	i = 0;
	closest = NULL;
	while (*(g_separators[i].sep))
	{
		ptr = ft_strstr(str, g_separators[i].sep);
		if (ptr && (!closest || (ptr < closest && closest)))
			closest = ptr;
		++i;
	}
	return (closest);
}

char	*unglue_sep(char *input)
{
	char	*new;
	char	*ptr;

	new = input;
	while ((ptr = get_closest_sep(new)))
	{
		ft_printf("%s\n", ptr);
		new = ptr;
		/* HERE IT ENDS FOR TODAY */
	}
	return (new);
}
