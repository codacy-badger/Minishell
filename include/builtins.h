/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:33:04 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/15 16:38:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** Functions in builtins.c
*/
int				cmd_exit(char **buf);
int				cmd_env(char **buf);

/*
** Functions in builtins_dispatcher.c
*/
int				builtins_select(char **buf);
typedef struct	s_builtins
{
	char	*key;
	int		(*f)(char**);
}				t_builtins;

#endif
