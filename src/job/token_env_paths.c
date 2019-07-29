

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
		ft_memdel((void**)&env_path);
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

char		*ft_concat_path(char *str, _Bool *more_path)
{
	static char	**ptok;
	static int	nb;
	static int	i;
	char		*full_path;

	if (!ptok)
	{
		ptok = ft_token_path();
		/*while (ptok && ptok[nb])
			++nb;
*/	}
	if (!ptok || i >= nb)
	{
		i = 0;
		nb = 0;
		ptok = NULL;
		*more_path = 0;
		return (NULL);
	}
	ft_printf("OKOK\n");
	full_path = ft_strjoin(ptok[i] ,"/");
	full_path = ft_strjoin(full_path , str);
	++i;
	return (full_path);
}
