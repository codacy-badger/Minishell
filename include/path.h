/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:13:49 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/21 14:47:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include <limits.h>

char	*short_path(char **cwd);

extern char	g_pwd[PATH_MAX];

#endif
