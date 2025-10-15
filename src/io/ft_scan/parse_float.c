/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:12:07 by pabellis          #+#    #+#             */
/*   Updated: 2025/07/30 20:54:33 by jaubry--         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

static bool	str_is_float(const char *line);

float	parse_float(const char *line, int line_number, t_limits limits)
{
	float	result;

	if (!str_is_float(line))
	{
		register_complex_err_msg(LFT_E_MSG_NOT_FLT, line_number);
		error(pack_err(LFT_ID, LFT_E_NOT_FLT), FL, LN, FC);
		errno = EINVAL;
		return (-1);
	}
	if (*line == '+')
		++line;
	result = ft_atod(line);
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

static bool	str_is_float(const char *line)
{
	int	i;

	i = 0;
	if (line[i] == '+' || line[i] == '-')
		++i;
	if (line[i] == '.' && !ft_isdigit(line[i + 1]))
		return (false);
	while (ft_isdigit(line[i]))
		++i;
	if (line[i] == '.')
		++i;
	while (ft_isdigit(line[i]))
		++i;
	if (*line && line[i] != '\0' && !ft_isspace(line[i]) && line[i] != ',')
		return (false);
	return (true);
}
