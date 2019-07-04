/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:13:49 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/04 21:32:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

char	*ft_getenv(const char *name);

int		ft_setenv(const char *name, const char *value, int overwrite);

char	**env_cpy(char **child_env);

char	*short_path(char **cwd);

#endif
