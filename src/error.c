/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:56:23 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/02 16:57:15 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

const struct s_error_desc	g_errordesc[] =
{
	{ e_success, "No error" },
	{ e_invalid_input, "Invalid input" },
	{ E_FILE_NOT_FOUND, "File not found" }
};
