/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:48:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/11 21:37:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
#define dquote "
#define quote '
#define cursh {
#define subsh (
#define bquote `
*/

char		is_quote_open(char c, char mask)
{
	if (c == '`')
		mask ^= '`';
	else if (c == '\"')
		mask ^= '\"';
	else if (c == '{' || (c == '}' && mask == ((1 << 1) | (1 << 2))))
		mask ^= ((1 << 1) | (1 << 2));
	else if (c == '(' || (c == ')' && mask == (1 << 0)))
		mask ^= (1 << 0);
	else if (c == '\'')
		mask ^= '\'';
	return (mask);
}

static char	*create_new_line(char *str, int *len)
{
	char	*new_line;

	new_line = (char*)ft_memalloc(*len);
	if (!new_line)
	{
		*len = -1;
		return (NULL);
	}
	else
	{
		if (str)
		{
			new_line = ft_strncpy(new_line, str, *len);
			free(str);
		}
		return (new_line);
	}
}

int			get_stdin(char **line)
{
	char	separator;
	int		len;
	int		ret;
	char	tmp;
	char	*new_line;

	separator = '\n';
	len = 0;
	ret = 0;
	new_line = NULL;
	while (1)
	{
		len += 128;
		new_line = create_new_line(new_line, &len);
		if (len == -1)
			return (-1);
		*line = new_line;
		while (ret < len)
		{
			tmp = ft_getch();
			if (tmp == separator || !tmp)
			{
				(*line)[ret] = 0;
				return (ret);
			}
			(*line)[ret] = tmp;
			++ret;
		}
	}
	return (ret);
}
