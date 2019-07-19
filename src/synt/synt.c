/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:59:39 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/16 18:46:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"
#include "synt_const.h"

const struct s_operator	g_operator[] =
{ {"||"}, {"&&"}, {">>"}, {"|"}, {"&"}, {"<"}, {">"}, {"\0"} };

int	operator_check(char *token)
{
	int	i;
	
	i = 0;
	while (g_operator[i].gram_op[0])
	{
		if (ft_strstr(token, g_operator[i].gram_op))
		{
			psherror(e_syntax_error, g_operator[i].gram_op);
			return (e_syntax_error);
		}
		++i;
	}
	return (0);
}

int	synt(char **cmd_line)
{
	int i;

	i = 0;
	if (cmd_line == NULL)
	{
		psherror(e_invalid_input, NULL);
		return (e_invalid_input);
	}
	while (cmd_line[i])
	{
		if (operator_check(cmd_line[i]))
			return (e_syntax_error);
		++i;
	}
	return (e_success);
}
