/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:59:39 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/16 13:50:57 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes a char* and returns (at each call) char** for each execve.
**
**
**   input : ls -l -- ok ; toto; echo "damn";
**
**                take a strsep(input) output
**				  
**                
**
**
**
**
**
**
**
**
**
**
**
*/

#include "libft.h"

char	**lexer(char *input)
{
	return (ft_strsplit(input, ' '));
}
