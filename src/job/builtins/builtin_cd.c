/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:52:32 by abarthel          #+#    #+#             */
/*   Updated: 2019/08/01 12:43:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.unix.com/man-page/posix/1posix/cd/
*/

#include <unistd.h>

#include "libft.h"
#include "error.h"

static int	refresh_pwd(void)
{
	char	*cwd;

	if (!(cwd = getcwd(NULL, 0)))
		return (e_system_call_error);
	if (ft_setenv("PWD", cwd, 1))
		return (e_cannot_allocate_memory);
	ft_memdel((void**)&cwd);
	return (0);
}

static int	change_dir(const char *path)
{
	int	ret;

	if (chdir(path))
		return (e_invalid_input);
	if ((ret = refresh_pwd()))
		return (ret);
	return (e_success);
}

static int	cdpath_concat(char **path)
{
	char	*beg;
	char	*env;
	char	*dir;
	char	*pathname;

	if (!(beg = ft_getenv("CDPATH")))
	{
		ft_memdel((void**)path);
		return (e_command_not_found);
	}
	env = ft_strdup(beg);
	beg = env;
	while ((dir = ft_strsep(&env, ":")))
	{
		pathname = ft_strnjoin(3, dir, "/", *path);
		if (!access(pathname, F_OK))
			break;
		ft_memdel((void**)&pathname);
	}
	ft_memdel((void**)&beg);
	ft_memdel((void**)path);
	if (dir)
	{
		*path = pathname;
		return (e_success);
	}
	return (e_command_not_found);
}

int		cmd_cd(int argc, char **argv)
{
	char	*path;
	int	ret;

	(void)argc;
	ret = e_success;

	/* options are to be parsed */

	if (argc < 2)
	{
		if (!(path = ft_getenv("HOME")))
			if (!(path = ft_getenv("PWD")))
				return (1);
	}
	else
	{
		path = ft_strdup(argv[1]);
		if (cdpath_concat(&path))
			path = argv[1];
	}
	if ((ret = change_dir(path)))
	{
		if (ret != e_invalid_input)
		{
			psherror(ret, argv[0], e_cmd_type);
			return (g_errordesc[ret].code);
		}
		else
		{
			ft_dprintf(STDERR_FILENO, "%s: %s: %s: %s\n",
			g_progname, argv[0], path, g_errordesc[e_no_such_file_or_directory].message);
			return (e_invalid_input);
		}
	}
	if (argv[1] != path) /* free is path has been allocated */
	{
		ft_printf("%s\n", path);
		ft_memdel((void**)&path);
	}
	return (ret);
}

