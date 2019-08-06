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

size_t	ft_varlen(const char *s, const char *closetag)
{
	size_t	len;
	char	*end;

	len = 0;
	if (*s && !*closetag)
	{
		while (s[len] &&
				((s[len] >= 'a' && s[len] <= 'z')
				 || (s[len] >= 'A' && s[len] <= 'Z')
				 || (s[len] >= '0' && s[len] <= '9')
				 || s[len] == '_'))
			++len;
	}
	else if (*s && *closetag)
	{
		end = ft_strstr(s, closetag);
		if (!end)
			return (len);
		len = (size_t)(end - s);
	}
	return (len);
}

char	*getenv_content(char *str, const char *closetag)
{
	char	*end;
	size_t	len;
	char	c;

	len = ft_varlen(str, closetag);
	if (!len)
		return (NULL);
	c = str[len];
	str[len] = '\0';
	end = ft_getenv(str);
	str[len] = c;
	return (end);
}
