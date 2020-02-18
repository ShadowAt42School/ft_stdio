/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_accessors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:43:09 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/17 19:48:41 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_command_line.h"

size_t				g_opts_count = 0;
static char			**g_arguments;
static t_option		*g_options = NULL;

void		cl_set_opts(t_option *opts, size_t opts_count)
{
	g_options = opts;
	g_opts_count = opts_count;
}

void		cl_set_arguments(char **args)
{
	g_arguments = args;
}

t_option	*cl_get_sopt(char opt)
{
	int		option;

	if (!g_options)
		return (NULL);
	option = cl_find_sopt(opt, g_options, g_opts_count);
	if (option == -1 || (g_options + option)->is_set == FALSE)
		return (NULL);
	return (g_options + option);
}

char		*cl_get_argument(void)
{
	char	*argument;

	if (!g_arguments)
		return (NULL);
	argument = *g_arguments;
	if (!argument)
		return (NULL);
	g_arguments++;
	return (argument);
}
