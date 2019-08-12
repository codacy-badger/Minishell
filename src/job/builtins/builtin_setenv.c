/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 19:13:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "error.h"

int		cmd_setenv(int argc, char **argv)
{
	if (argc != 3)
	{
		psherror(e_invalid_input, argv[0], e_cmd_type);
		ft_dprintf(STDERR_FILENO, "Usage: %s VAR [VALUE]\n", argv[0]);
		return (g_errordesc[e_invalid_input].code);
	}
	else
	{
		if ((ft_setenv(argv[1], argv[2], 1)))
			return (g_errordesc[e_cannot_allocate_memory].code);
	}
	return (e_success);
}
