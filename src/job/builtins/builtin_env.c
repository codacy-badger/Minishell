/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 19:13:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_getopt.h"
#include "libft.h"
#include "error.h"
#include "job.h"

int		cmd_env(int argc, char **argv)
{
	extern char	**environ;
	char		**env_copy;
	int		opt;
	_Bool		i;

	i = 0;
	while ((opt = ft_getopt(argc, argv, ":i")) != -1)
		if (opt == 'i')
			i |= 1;
	if (g_optind == 1) /* case only env */
	{
		ft_print_tables(environ);
		g_optind = 0;
		return (0);
	}
	if (i)
	{
		if (argv[2])
			opt = job(&argv[2], NULL);
		else
			opt = 0;
		g_optind = 0;
		return (opt);
	}
	env_copy = environ;
	while (g_optind < argc)
	{
		ft_printf(">%s\n", argv[g_optind]);
		++g_optind;
	}
/*	if ((set_an_env_copy(&env_copy, argv, argc, i)))
	{
		psherror(e_cannot_allocate_memory, argv[0], e_cmd_type);
		return (g_errordesc[e_cannot_allocate_memory].code);
	}
*/	job(&argv[g_optind], env_copy); /* find a way to set argv to beg */
	g_optind = 0;
	return (0);
}
