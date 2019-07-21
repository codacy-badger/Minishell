/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:56:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 18:56:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "error.h"

char	*g_progname;

const struct s_error_desc	g_errordesc[] =
{
	{ 0, "no error" },
	{ 1, "invalid input" },
	{ 1, "syntax error near unexpected token" },
	{ 1, "no such builtin" },
	{ 126, "permission denied" },
	{ 127, "command not found" }
};

void	psherror(int e_error, char *str)
{
	if (str)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s \'%s\'\n", \
				g_progname, g_errordesc[e_error].message, str);
	}
	else
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", \
				g_progname, g_errordesc[e_error].message);
	}
}
