

#include <stdlib.h>
#include "libft.h"

/*
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
*/
char		*ft_concat_path(char *str, _Bool *more_path)
{
	*more_path = 0;
	return (str);
}
