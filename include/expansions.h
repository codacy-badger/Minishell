/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:35 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 18:40:54 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H
# include <stdlib.h>

struct	s_tags
{
	char	*opentag;
	size_t	(*f)(char**, const char*, const char*);
	char	*closetag;
};

int		treat_expansions(char **tokens);
char		*getenv_content(char *str, const char *closetag);
size_t		ft_varlen(const char *s, const char *closetag);
size_t		parameter_expansions(char **str, const char *opentag, const char *closetag);
size_t		tilde_expansion(char **str, const char *opentag, const char *closetag);

#endif
