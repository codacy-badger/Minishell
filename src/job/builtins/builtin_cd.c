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

#include "ft_getopt.h"
#include "libft.h"
#include "error.h"
/*
static int	set_oldpwd(void)
{
	char	*cwd;
	_Bool	allocated;

	allocated = 0;
	if (!(cwd = ft_getenv("PWD")))
	{
		allocated = 1;
		if (!(cwd = getcwd(NULL, 0)))
			return (e_system_call_error);
	}
	if (ft_setenv("OLDPWD", cwd, 1))
	{
		if (allocated)
			ft_memdel((void**)&cwd);
		return (e_cannot_allocate_memory);
	}
	if (allocated)
		ft_memdel((void**)&cwd);
	return (0);
}

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
	if ((ret = set_oldpwd()))
		return (ret);
	if ((ret = refresh_pwd()))
		return (ret);
	return (e_success);
}
*/
static int	cdpath_concat(char **path)
{
	char	*beg;
	char	*env;
	char	*dir;
	char	*pathname;

	if (!(beg = ft_getenv("CDPATH")))
		return (e_command_not_found);
	if (!(env = ft_strdup(beg)))
		return (e_cannot_allocate_memory);
	beg = env;
	while ((dir = ft_strsep(&env, ":")))
	{
		if (!(pathname = ft_strnjoin(3, dir, "/", *path)))
			return (e_cannot_allocate_memory);
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
	char	*oldpwd;
	int	opt;
	int	ret;
	_Bool	p;

	/* set variables */
	path = NULL;
	ret = e_success;
	p = 0;
 	
	/* parse options */
	g_opterr = 1;
	while ((opt = ft_getopt(argc, argv, "+LP")) != -1)
	{
		if (opt == 'P')
			p |= 1;
		else if (opt == '?')
		{
			ft_dprintf(STDERR_FILENO, "%1$s: usage: %1$s [-L|-P] [dir]\n", argv[0]);
			return (2);
		}
	}

	/* Execute  */
	if (!argv[g_optind])
	{
		if (!(path = ft_getenv("HOME")))
			if (!(path = ft_getenv("PWD")))
				return (1);
		path = ft_strdup(path);
	}
	else if (!ft_strcmp(argv[g_optind], "-"))
	{
		if (!(oldpwd = ft_getenv("OLDPWD")))
		{
			ft_dprintf(STDERR_FILENO, "%s: %s: OLDPWD not set\n", g_progname, argv[0]);
			return (e_invalid_input);
		}
		path = ft_strdup(oldpwd);
	}
	else
	{
		path = ft_strdup(argv[g_optind]);
		if ((ret = cdpath_concat(&path)) == e_cannot_allocate_memory)
			return (g_errordesc[e_cannot_allocate_memory].code);
		else if (!ret)
			ft_printf("%s\n", path);
	}
/*	if ((ret = change_dir(path)))
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
*/	ft_memdel((void**)&path);
	return (ret);
}
