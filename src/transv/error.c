/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:56:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 17:55:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "error.h"

char	*g_progname;

const struct s_error_desc	g_errordesc[] =
{
	{ e_success, "No error" },
	{ e_syntax_error, "syntax error near unexpected token"},
	{ e_no_builtin, "no such builtin" },
	{ e_file_not_found, "File not found" },
	{ e_command_not_found, "command not found"}
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
