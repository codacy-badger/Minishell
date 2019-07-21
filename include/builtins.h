/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:33:04 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/21 13:19:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

/*
** Functions in builtins.c
*/
int				cmd_echo(char **argv);
int				cmd_exit(char **argv);
int				cmd_env(char **argv);
int				cmd_cd(char **argv);

/*
** Functions in builtins_dispatcher.c
*/
int				builtins_select(char **argv);
typedef struct	s_builtins
{
	char	*key;
	int		(*f)(char**);
}				t_builtins;

#endif
