/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:03:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/25 21:48:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "error.h"

/*
static int	hasaccess(char *str)
{
	int	ret;

	ret = access(str, F_OK);
}


static _Bool	is_path(char *str)
{

}
*/
int	path_concat(char **bin)
{
	(void)bin;
	if (access(*bin, F_OK))
	{
		
		return (e_success);
	}
	return (e_success);
}
