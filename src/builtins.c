/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/06 21:50:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

_Bool	builtins_select(char **buf)
{
	extern char	**environ;

	if (!ft_strcmp(*buf, "exit"))
	{
		ft_tabdel(&environ);
		ft_memdel((void**)buf);
		exit (0);
	}
	else if (!ft_strcmp(*buf, "env")) /* get arg and go to getenv() ft */
	{
		ft_print_tables(environ);
		ft_memdel((void**)buf);
		return (1);
	}
	else
		return (0);
}
