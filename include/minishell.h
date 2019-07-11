/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:33:04 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/11 18:42:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

int				get_stdin(char **line);
_Bool			prompt_display(int status);

int				builtins_select(char **buf);
int				cmd_exit(char **buf);
int				cmd_env(char **buf);

typedef struct	s_builtins
{
	char	*key;
	int		(*f)(char**);
}				t_builtins;

#endif
