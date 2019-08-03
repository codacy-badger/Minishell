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

struct	s_opening_tag
{
	char	*opentag;
	int	(*function)(char**, const char*, const char*);
	char	*closetag;
};

int		treat_expansions(char **tokens);
int		ft_dollar_expansion(char **str, const char *opentag, const char *closetag);
int		ft_bracket_expansion(char **str, const char *opentag, const char *closetag);

#endif
