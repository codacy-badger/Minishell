/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
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

size_t	ft_alnumlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (s[len] &&
				((s[len] >= 'a' && s[len] <= 'z')
				 || (s[len] >= 'A' && s[len] <= 'Z')
				 || (s[len] >= '0' && s[len] <= '9')
				 || s[len] == '_'))
		{
			++len;
		}
	}
	return (len);
}

char	*getenv_content(char *str, const char *closetag)
{
	char	*end;
	size_t	len;
	char	c;

	if (*closetag)
	{
		end = ft_strstr(str, closetag);
		len = (size_t)(end - str);
		str[len] = '\0';
		end = ft_getenv(str);
		str[len] = *closetag;
		return (end);
	}
	else
	{
		len = ft_alnumlen(str);
		c = str[len];
		str[len] = '\0';
		end = ft_getenv(str);
		str[len] = c;
		return (end);
	}
}
