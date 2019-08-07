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

int	isvalid_param(const char c)
{
	if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		 || (c >= '0' && c <= '9') || c == '_'))
		return (1);
	else
		return (0);
}

size_t	ft_varlen(const char *s, const char *closetag)
{
	size_t	len;
	char	*end;

	len = 0;
	if (*s && !*closetag)
	{
		while (s[len] && isvalid_param(s[len]))
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

int	getenv_content(char **content, char *str, const char *closetag)
{
	size_t	len;
	size_t	i;
	char	c;

	i = 0;
	len = ft_varlen(str, closetag);
	if (!len)
		return (e_bad_substitution);
	c = str[len];
	str[len] = '\0';
	while (str[i])
	{
		if (!isvalid_param(str[i]))
		{
			str[len] = c;
			return (e_bad_substitution);
		}
		++i;
	}
	*content = ft_getenv(str);
	str[len] = c;
	return (e_success);
}
