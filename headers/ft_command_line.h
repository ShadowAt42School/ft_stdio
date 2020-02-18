/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:10:40 by maghayev          #+#    #+#             */
/*   Updated: 2020/02/17 19:52:15 by maghayev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_LINE_H
# define FT_COMMAND_LINE_H
# include "libft.h"

# define ERROR_NO_OPTION 404

typedef struct	s_option_param {
	t_bool			has_param;
	t_bool			mult;
	void			*param;
	char			type;
}				t_option_param;

typedef struct	s_option {
	char			shortc;
	char			*longc;
	char			*desc;
	t_bool			mandatory;
	t_bool			is_set;
	t_option_param	param;
}				t_option;

extern size_t		g_opts_count;

void			cl_engine(char **args, t_option *options, size_t opts_count);
void			cl_engine_options_s(char **argums,
												t_option *opts, size_t optsc);
void			cl_engine_options_l(char **argums,
												t_option *opts, size_t optsc);
void			cl_engine_argument(char **argums, size_t count);

/*
**	Parsers
*/
void			cl_parse_argum(t_option *opt);
void			cl_parse_argum_warg(t_option *opt, char *argm);

/*
**	Helper Functions
*/
t_int			cl_find_sopt(char opt, t_option *opts, size_t optsc);
t_int			cl_find_lopt(char *opt, t_option *opts, size_t optsc);
void			cl_set_arguments(char **args);
char			*cl_get_argument();
void			cl_set_opts(t_option *opts, size_t opts_count);
t_option		*cl_get_sopt(char opt);

#endif
