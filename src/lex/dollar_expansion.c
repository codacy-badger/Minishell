/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
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

int	ft_dollar_expansion(char **str, const char *opentag, const char *closetag)
{
	char	*word;
	char	*varname;
	char	*envvar;
	char	*previous;
	size_t	len;

	(void)closetag;
	(void)opentag;
	previous = NULL;	
	while ((word = ft_strchr(*str, '$')))
	{
		++word;
		len = ft_alnumlen(word);
		++len;
		if (len)
		{
			if (!(varname = (char*)ft_memalloc(sizeof(char) * (len + 1))))
				return (e_cannot_allocate_memory);
			--word;
			while (len)
			{
				--len;
				varname[len] = word[len];
			}
			envvar = ft_getenv(&varname[1]);
			if (envvar == previous)
			{
				ft_memdel((void**)&varname);
				break;
			}
			previous = envvar;
			if (!envvar)
			{
				if (!(*str = ft_strrep(str, "", varname)))
				{
					ft_memdel((void**)&varname);
					return (e_cannot_allocate_memory);
				}
			}
			else
			{
				if (!(*str = ft_strrep(str, envvar, varname)))
				{
					ft_memdel((void**)&varname);
					return (e_cannot_allocate_memory);
				}
			}
			ft_memdel((void**)&varname);
		}

	}
	return (e_success);
}
