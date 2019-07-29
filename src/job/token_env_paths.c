

#include <stdlib.h>
#include "libft.h"


static char	**ft_tokenv(char *name)
{
	char	*env_path;
	char	**path_tokens;

	env_path = NULL;
	if (name)
	{
		env_path = ft_getenv(name);
	}
	if (env_path)
	{
		path_tokens = ft_strsplit(env_path, ':');
		return (path_tokens);
	}
	else
	{
		return (NULL);
	}
}

static char	**ft_token_path(void)
{
	char	**path_tokens;

	path_tokens = ft_tokenv("PATH");
	return (path_tokens);
}

char		*ft_concat_path(char *str)
{
	static char	**ptok;
	static int	nb;
	static int	i;
	char		*full_path;

	if (!ptok && str)
	{
		i = 0;
		nb = 0;
		ptok = ft_tabcpy(ft_token_path());
		while (ptok && ptok[nb])/* heap buff overflow here*/
			++nb;
	}
	if (!ptok || i >= nb || !str)
	{
		ptok = NULL;
		return (NULL);
	}
	full_path = ft_strnjoin(3, ptok[i] , "/", str);
	++i;
	return (full_path);
}
