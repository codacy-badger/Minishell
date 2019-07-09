/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:56:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/09 12:31:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

const struct s_error_desc	g_errordesc[] =
{
	{ e_success, "No error" },
	{ e_invalid_input, "Invalid input" },
	{ e_file_not_found, "File not found" },
	{ e_command_not_found, "command not found"}
};
