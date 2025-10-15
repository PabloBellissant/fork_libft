/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 06:16:39 by pabellis          #+#    #+#             */
/*   Updated: 2025/07/30 20:54:45 by jaubry--         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <errno.h>
#include "libft.h"

static bool	str_is_integer(const char *line);

int	parse_int(const char *line, int line_number, t_limits limits)
{
	int	result;

	if (!str_is_integer(line))
	{
		register_complex_err_msg(LFT_E_MSG_NOT_INT, line_number);
		error(pack_err(LFT_ID, LFT_E_NOT_INT), FL, LN, FC);
		errno = EINVAL;
		return (-1);
	}
	result = ft_atoi(line);
	if (result > limits.max || result < limits.min)
	{
		register_complex_err_msg(LFT_E_MSG_FLT_RANGE, limits.min, limits.max,
			line_number);
		error(pack_err(LFT_ID, LFT_E_FLT_RANGE), FL, LN, FC);
		errno = EINVAL;
		return (-1);
	}
	return (result);
}

static bool	str_is_integer(const char *line)
{
	if (*line == '+' || *line == '-')
		++line;
	if (!ft_isdigit(*line))
		return (false);
	while (ft_isdigit(*line))
		++line;
	if (!*line || ft_isspace(*line) || *line == ',' || *line == '/'
		|| *line == '\n')
	{
		return (true);
	}
	return (false);
}
