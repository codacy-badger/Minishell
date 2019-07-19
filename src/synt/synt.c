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

int	synt(char **cmd_line)
{
	int i;

	i = 0;
	if (cmd_line == NULL)
	{		ft_dprintf(2, "Minishell: %s \'%s\'\n", g_errordesc[e_invalid_input].message, "|");
		return (e_invalid_input);
	}
	while (cmd_line[i])
	{
	/*	if (ft_strstr(cmd_line[i], "|"))
		{
			ft_dprintf(2, "Minishell: %s \'%s\'\n", g_errordesc[e_syntax_error].message, "|");
			return (e_syntax_error);
		}*/
		++i;
	}
	return (e_success);
}
