/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 19:14:19 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "error.h"

int	cmd_exit(int argc, char **argv)
{
	extern char	**environ;
	unsigned char	status;

	status = 0;
	if (argc == 2)
	{
		if (*argv[1]
			&& (((*argv[1] == '-' || *argv[1] == '+') && ft_str_is_numeric(&argv[1][1]))
			|| ft_str_is_numeric(argv[1])))
				status = (unsigned char)ft_atoi(argv[1]);
		else
		{
			ft_dprintf(STDERR_FILENO,
			"%s: %s: %s: numeric argument required\n",
					g_progname, argv[0], argv[1]);
			return (2);
		}
	}
	ft_tabdel(&argv);
	ft_tabdel(&environ);
	exit(status);
}
