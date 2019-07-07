/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:38:55 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/07 14:36:22 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "path.h"

_Bool	prompt_display(int status)
{
	int		ret;
	char	*pwd;

	if (status)
	{
		ret = ft_printf(
				"\e[1m\e[38;5;14m%s \e[0m\e[38;5;160m⦗%d⦘ ➠ \e[0m",
				short_path(&pwd), status);
		ft_memdel((void**)&pwd);
	}
	else
	{
		ret = ft_printf("\e[1m\e[38;5;14m%s\e[0m\e[38;5;82m ➠ \e[0m",
				short_path(&pwd));
		ft_memdel((void**)&pwd);
	}
	return (ret);
}
