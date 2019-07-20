/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jcont.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:59:39 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/16 18:46:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "job.h"

static char	**ft_sequence(char ***cmd)
{
	char **seq;
	int	i;

	i = 0;
	seq = NULL;
	while ((*cmd)[i] && !ft_strstr((*cmd)[i], ";"))
	{
		++i;
	}
	seq = (char**)ft_tabmalloc(i + 1);
	i = 0;
	while ((*cmd)[i] && *((*cmd)[i]) != ';')
	{
		seq[i] = ft_strdup((*cmd)[i]);
		++i;
	}
	++i;
	*cmd = &(*cmd)[i];
	return (seq);
}

int	jcont(char **cmd, char **envp)
{
	char	**argv;
	int	ret;
	int	len;
	int	i;

	len = ft_tablen(cmd);
	i = 0;
	while (i < len)
	{
		++i;
		argv = ft_sequence(&cmd);
		ret = job(argv, envp);
	}
	/*ft_tabdel(&argv);*/
	return (ret);
}
