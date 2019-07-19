/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:51:41 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/17 17:33:21 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum	e_minishell_error
{
	e_file_not_found = -2,
	e_invalid_input = -1,
	e_success = 0,
	e_syntax_error = 1,
	e_permission_denied = 126,
	e_command_not_found = 127
};

typedef enum e_minishell_error	t_error;

struct	s_error_desc
{
	int		code;
	char	*message;
};

extern const struct s_error_desc	g_errordesc[];

#endif
