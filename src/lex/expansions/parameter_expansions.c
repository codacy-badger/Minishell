/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_expansions.c                             :+:      :+:    :+:   */
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

/*
static int	replace_by_retval(char **str, int ret)
{
	char	*value;

	value = ft_itoa(ret);
	if (!value)
		return (e_cannot_allocate_memory);
	if (!(*str = ft_strrep(str, value, "$?")))
		return (e_cannot_allocate_memory);
	else
	{
		ft_memdel((void**)&value);
		return (e_success);
	}
}
*/

size_t	parameter_expansions(char **str, const char *opentag, const char *closetag)
{
	char	*new;
	char	*rest;
	char	*content;
	size_t	lopen;
	size_t	lvarname;
	size_t	lclose;
	size_t	lcontent;
	size_t	lrest;

	lopen = ft_strlen(opentag);
	lvarname = ft_varlen(&(*str)[lopen], closetag);
	lclose = ft_strlen(closetag);
	rest = &(*str)[lopen + lvarname + lclose];
	lrest = ft_strlen(rest);
	content = getenv_content(&(*str)[lopen], closetag);
	lcontent = ft_strlen(content);
	new = (char*)ft_memalloc(sizeof(char) * (lrest + lcontent + 1));
	ft_strncat(new, content, lcontent);
	ft_strncat(new, rest, lrest);
	*str = new;
	return (lcontent);
}
