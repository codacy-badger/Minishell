/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/16 18:24:21 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	cmd_exit(char **buf)
{
	extern char **environ;

	ft_tabdel(&environ);
	ft_memdel((void**)buf);
	exit(0);
}

int	cmd_env(char **buf)
{
	extern char **environ;

	ft_print_tables(environ);
	ft_memdel((void**)buf);
	return (0);
}

int cmd_history(char **buf)
{
	extern char **environ;

	ft_print_tables(environ);
	ft_memdel((void**)buf);
	return (0);
}
