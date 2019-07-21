/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:51:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 18:54:34 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum	e_minishell_error
{
	e_success,
	e_invalid_input,
	e_syntax_error,
	e_no_builtin,
	e_permission_denied,
	e_command_not_found
};

typedef enum e_minishell_error	t_error;

struct	s_error_desc
{
	int		code;
	char	*message;
};

extern const struct s_error_desc	g_errordesc[];
extern char	*g_progname;

void	psherror(int e_error, char *str);

#endif
