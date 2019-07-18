/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:48:52 by abarthel          #+#    #+#             */
/*   Updated: 2019/07/16 13:02:27 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Physical Module handling inputs in a zsh style.
** It does not include termcaps.
** Files: input.c, input.h
** Use: call get_stdin in your program in a get_next_line alike fashion.
*/

#include <stdlib.h>
#include "libft.h"

/*
** PRINT_QUOTE
** Displays the corresponding quote message according to the mask value.
** ` -> bquote
** { -> cursh
** ( -> subsh
** " -> dquote
** ' -> quote
*/

static void		print_quote(char mask)
{
	if (mask == '`')
		ft_printf("bquote> ");
	else if (mask == '\"')
		ft_printf("dquote> ");
	else if (mask == ((1 << 1) | (1 << 2)))
		ft_printf("cursh> ");
	else if (mask == (1 << 0))
		ft_printf("subsh> ");
	else if (mask == '\'')
		ft_printf("quote> ");
}

/*
** IS_QUOTE_OPEN
** Checks whether a quote or bracket is open in this case it return a mask.
** As long as the mask has a different value from 0 the "print_quote" element
** is display after a newline character.
*/

static char		is_quote_open(char c, char mask)
{
	if (c == '`')
		mask ^= '`';
	else if (c == '\"')
		mask ^= '\"';
	else if (c == '{' || (c == '}' && mask == ((1 << 1) | (1 << 2))))
		mask ^= ((1 << 1) | (1 << 2));
	else if (c == '(' || (c == ')' && mask == (1 << 0)))
		mask ^= (1 << 0);
	else if (c == '\'')
		mask ^= '\'';
	return (mask);
}

/*
** CREATE_NEW_LINE
** Reallocates memory (extends it). it "mimics" the realloc function.
*/

static char		*create_new_line(char *str, int *len)
{
	char	*new_line;

	new_line = (char*)ft_memalloc(*len);
	if (!new_line)
	{
		*len = -1;
		return (NULL);
	}
	else
	{
		if (str)
		{
			new_line = ft_strncpy(new_line, str, *len);
			free(str);
		}
		return (new_line);
	}
}

/*
** Gets characters from standard inputs as zsh does. Do not contains termcaps
** '\n' needs to be define as separator by default when called.
*/

int				get_block(char **line, int len, char separator)
{
	int			ret;
	static char	mask;
	char		c;

	ret = 0;
	c = 0;
	while (ret < len)
	{
		c = ft_getch();
		mask = is_quote_open(c, mask);
		if ((c == separator && !mask) || !c)
		{
			(*line)[ret] = 0;
			return (ret);
		}
		else if (c == separator && mask)
			print_quote(mask);
		(*line)[ret] = c;
		++ret;
	}
	if (ret == len)
		return (-1);
	else
		return (1);
}

/*
** GET_STDIN
** Manages to get blocks from stdin. it reallocates memory if needed and call
** a function that get "lines" from stdin.
** It gets the inputi (get_blocks) from stdin wich is written on 128b blocks
** by default. If 128b are not enough, it extends it by its size, i.e. *2.
*/

int				get_stdin(char **line)
{
	int		len;
	int		ret;
	char	*new_line;

	len = 0;
	ret = 0;
	new_line = NULL;
	while (1)
	{
		len += 128;
		new_line = create_new_line(new_line, &len);
		if (len == -1)
			return (-1);
		*line = new_line;
		if ((ret = get_block(line, len, '\n')) == -1)
			continue ;
		else
			return (1);
	}
	return (ret);
}
