/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:59:39 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 16:54:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The lexer should token ; and || | or other const.
 * It must lean the tokens from \t and other "blanks" */

char	**lexer(char *input)
{
	return (ft_strsplit(input, ' '));
}
