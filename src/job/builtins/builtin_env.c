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
#include "builtins.h"
#include "libft.h"
#include "error.h"
#include "job.h"

static int	set_envcpy(char *arg, char ***env_cpy, char *pequal)
{
	char	*name;

	*pequal = '\0';
	if (!(name = ft_strdup(arg)))
		return (e_cannot_allocate_memory);
	*pequal = '=';
	++pequal;
	ft_putenv_table(env_cpy, name, pequal, 1);
	ft_memdel((void**)&name);
	return (1);
}

int		cmd_env(int argc, char **argv)
{
	extern char	**environ;
	char		**env_copy;
	char		*pequal;
	int		opt;
	_Bool		i;

	i = 0;
	if (argc == 1)
	{
		ft_print_tables(environ);
		g_optind = 0;
		return (0);
	}
	while ((opt = ft_getopt(argc, argv, ":i")) != -1)
		if (opt == 'i')
			i |= 1;
	if (i)
	{
		if (argc == 2)
		{
			g_optind = 0;
			return (0);
		}
		env_copy = NULL;
	}
	else
		env_copy = ft_tabcpy(environ);
	while (g_optind < argc && (pequal = ft_strstr(argv[g_optind], "=")))
	{
		set_envcpy(argv[g_optind], &env_copy, pequal);
		++g_optind;
	}
	job(&argv[g_optind], env_copy);
	ft_tabdel(&env_copy);
/*	env_copy = NULL;
*/	g_optind = 0;
	return (0);
}
