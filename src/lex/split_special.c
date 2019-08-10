/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_splecial.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:58:26 by abarthel          #+#    #+#             */
/*   Updated: 2019/06/26 15:00:22 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char *str, char *whitespaces)
{
	char	*cpy;
	int	nb;

	nb = 0;
	if (!(cpy = ft_strdup(str)))
		return (-1);
	if (ft_strtok(cpy, whitespaces))
		++nb;
	else
	{
		ft_memdel((void**)&cpy);
		return (nb);
	}
	while (ft_strtok(NULL, whitespaces))
		++nb;
	ft_memdel((void**)&cpy);
	return (nb);
}

static int	copy_tab(char *str, char *whitespaces, char **tokens)
{
	char	*tok;
	char	*cpy;
	int	nb;

	nb = 0;
	if (!(cpy = ft_strdup(str)))
	{
		ft_tabdel(&tokens);
		return (-1);
	}
	if ((tok = ft_strtok(cpy, whitespaces)))
	{
		if (!(tokens[nb] = ft_strdup(tok)))
		{
			ft_tabdel(&tokens);
			return (-1);
		}
		++nb;
	}
	else
	{
		ft_tabdel(&tokens);
		ft_memdel((void**)&cpy);
		return (-1);
	}
	if (ft_strstr(tok, "\""))
	{
		ft_printf("|%s\n", tok);
	}
	while ((tok = ft_strtok(NULL, whitespaces)))
	{
		if (!(tokens[nb] = ft_strdup(tok)))
		{
			ft_tabdel(&tokens);
			return (-1);
		}
		++nb;
		if (ft_strstr(tok, "\""))
		{
			ft_printf("|%s\n", tok);
		}
	}
	ft_memdel((void**)&cpy);
	return (0);
}

char		**split_special(char *str)
{
	char	**tokens;
	char	*whitespaces;
	int	nb_words;

	whitespaces = " \t\n\v\f\r";
	if ((nb_words = count_words(str, whitespaces)) <= 0
		|| !(tokens = (char**)ft_tabmalloc(nb_words + 1))
		|| copy_tab(str, whitespaces, tokens) == -1)
		return (NULL);
	return (tokens);
}
