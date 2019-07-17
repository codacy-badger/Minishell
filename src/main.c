/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:32:13 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/17 15:58:52 by abarthel         ###   ########.fr       */
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
#include "job.h"

int	main(void)
{
	extern char			**environ;
	int			stat;
	char		*input;
	char		**argv;

	environ = ft_envcpy(environ);
	stat = 0;
	argv = NULL;
	while (prompt_display(WEXITSTATUS(stat)) && get_stdin(&input) >= 0)
	{
		argv = lexer(input);
		free(input);
		stat = job(argv, environ);
	}
	ft_tabdel(&environ);
	return (0);
}
