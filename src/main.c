/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/17 20:06:37 by abarthel         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	extern char			**environ;
	int			ret;
	char		*input;
	char		**args;

	(void)argc;
	g_progname = argv[0];
	environ = ft_tabcpy(environ);
	ret = 0;
	args = NULL;
	while (prompt_display(ret) && get_stdin(&input) >= 0)
	{
		args = lexer(input);
		ft_memdel((void**)&input);
		ret = synt(args);
		if (ret != e_success)
			continue;
		ret = jcont(args, environ);
	}
	ft_tabdel(&environ);
	return (0);
}
