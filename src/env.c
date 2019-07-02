/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:54:14 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/02 18:37:54 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_getenv(const char *name)
{
	extern char **environ;

	if (!name)
		ft_print_tables(environ);
	else
	{
		(void)name;
	}
	return (NULL);
}
