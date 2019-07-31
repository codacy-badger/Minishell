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

/* The lexer should tokenize || ; & && ect even if glued to words
 * example : echo ok;ls||env */
char	**lexer(char *input)
{
	char **tokens;
	char **retsplit;

	retsplit = ft_strsplit_whitespaces(input);
	tokens = ft_tabcpy(retsplit);
	ft_tabdel(&retsplit);
	return (tokens);
}
