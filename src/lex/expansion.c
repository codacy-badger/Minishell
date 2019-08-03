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

#include <stdlib.h>
#include "libft.h"
#include "error.h"
#include "expansion.h"

static int	ft_bracket_expansion(char **str)
{
	char	*word;
	char	*varname;
	char	*envvar;
	char	*previous;
	size_t	len;

	previous = NULL;	
	while ((word = ft_strstr(*str, "${")))
	{
		word += 2;
		len = ft_alnumlen(word);
		len += 3;
		if (len)
		{
			if (!(varname = (char*)ft_memalloc(sizeof(char) * (len + 1))))
				return (e_cannot_allocate_memory);
			word -= 2;
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

static int	ft_simple_expansion(char **str)
{
	char	*word;
	char	*varname;
	char	*envvar;
	char	*previous;
	size_t	len;

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

const struct s_opening_tag	g_function_list[] =
{
	{"${", &ft_bracket_expansion, "}"},
	{"$", &ft_simple_expansion, NULL},
	{"\0", NULL, NULL}
};

static void		*expansion_dispatcher(char *str)
{
	int	i;

	i = 0;
	while (*(g_function_list[i].opentag))
	{
		if (ft_strstr(str, g_function_list[i].opentag))
			return (g_function_list[i].function);
		++i;
	}
	return (NULL);
}

int			treat_expansions(char **tokens)
{
	char	*(*function)(char*);
	int		i;
	int		ret;

	i = 0;
	if (!tokens)
		return (e_invalid_input);
	while (tokens[i])
	{
		if ((function = expansion_dispatcher(tokens[i])))
		{
			if ((ret = ft_simple_expansion(&tokens[i])))
				psherror(ret, tokens[i], e_cmd_type);
			ft_printf("after|%s\n", tokens[i]); /* check expansion */
		}
		++i;
	}
	return (e_success);
}
