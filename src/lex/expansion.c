/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:07:44 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 17:14:58 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error.h"

int	treat_expansions(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return (e_invalid_input);
	while (tokens[i])
	{
		ft_printf("%s\n", tokens[i]);
		++i;
	}
	return (e_success);
}
