/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_expansion.c                                :+:      :+:    :+:   */
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

int	ft_replace_expansion(char **str, const char *opentag, const char *closetag)
{
	char	*word;
	char	*content;
	char	*expansion;
	char	*varname;
	char	*previous;
	size_t	len;
	size_t	lopen;

	previous = NULL;
	while ((word = ft_strstr(*str, opentag)))
	{
		lopen = ft_strlen(opentag);
		word += lopen;
		if (!(len = ft_varlen(word, closetag)))
			return (e_success);
		if (!(varname = ft_strndup(word, len)))
			return (e_cannot_allocate_memory);
		if (!(expansion = ft_strnjoin(3, (char*)opentag, (char*)varname, closetag)))
		{
			ft_memdel((void**)&varname);
			return (e_cannot_allocate_memory);
		}
		ft_memdel((void**)&varname);
		content = getenv_content(word, closetag);
		if (content && previous == content)
		{
			ft_memdel((void**)&expansion);
			break;
		}
		previous = content;
		if ((*str = ft_strrep(str, content ? content : "", expansion)))
		{
			ft_memdel((void**)&expansion);
			break;
		}
		else
		{
			ft_memdel((void**)&expansion);
			return (e_cannot_allocate_memory);
		}
	}
	return (e_success);
}
