/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 18:04:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "builtins.h"
#include "prompt.h"
#include "input.h"
#include "error.h"
#include "lexer.h"
#include "jcont.h"
#include "synt.h"

char	g_alret[3] = {0};
int	g_retval = 0;

int	set_minimal_env(void)
{
	extern char	**environ;
	/* call env setenv ft 
	   PWD=/home/antoine/Minishell
	   SHLVL=1
	   _=/usr/bin/env*/
	ft_print_tables(environ);
	return (e_success);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	char		*input;
	char		**args;

	(void)argc;
	g_progname = argv[0];
	environ = ft_tabcpy(environ);
	g_retval = e_success;
/*	set_minimal_env();
*/	while (prompt_display(g_retval) && get_stdin(&input) >= 0)
	{
		args = lexer(input);
		ft_memdel((void**)&input);
		if (!args)
			continue;
		g_retval = synt(args);
		if (g_retval != e_success)
		{
			ft_tabdel(&args);
			continue;
		}
		g_retval = jcont(args, environ);
		ft_tabdel(&args);
	}
	ft_tabdel(&environ);
	return (0);
}
