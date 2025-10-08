/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 04:44:01 by pabellis          #+#    #+#             */
/*   Updated: 2025/08/06 07:20:41 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <limits.h>
#include "libft.h"

float			parse_float(const char *line, int line_number, t_limits limits);
int				parse_int(const char *line, int line_number, t_limits limits);
static t_limits	limits(char type, const char *format);
static const char		*get_end_token(const char *line, const char *format);
char			*parse_str(const char *line);

int	parse_type(va_list *args, const char **line,
	int line_num, const char *format)
{
	t_result	result;

	errno = 0;
	result.float_t = va_arg(*args, void *);
	if (*format == 'f')
		*result.float_t = parse_float(*line, line_num, limits(*format, format));
	else if (*format == 'd')
		*result.int_t = parse_int(*line, line_num, limits(*format, format));
	else if (*format == '8')
		*result.uint8_t = parse_int(*line, line_num, limits(*format, format));
	else if (*format == 's')
		*result.string = parse_str(*line);
	if (errno != 0)
		return (-1);
	*line = get_end_token(*line, format);
	return (0);
}

static t_limits	limits(char type, const char *format)
{
	int	temp;

	++format;
	if (*format != '[')
	{
		if (type == 'd')
			return ((t_limits){INT_MIN, INT_MAX});
		if (type == '8')
			return ((t_limits){0, 255});
		return ((t_limits){INT_MIN, INT_MAX});
	}
	++format;
	if (!ft_strchr(format, ',')
		|| ft_strchr(format, ',') > ft_strchr(format, ']'))
	{
		return ((t_limits){0, ft_atoi(format)});
	}
	temp = ft_atoi(format);
	format = ft_strchr(format, ',') + 1;
	return ((t_limits){temp, ft_atoi(format)});
}

static const char	*get_end_token(const char *line, const char *format)
{
	if (*format == 's')
	{
		while (*line && !ft_isspace(*line) && *line != '\n')
			++line;
		return (line);
	}
	while (*line && !ft_isspace(*line) && *line != '\n' && *line != ','
		&& *line != '/')
	{
		++line;
	}
	return (line);
}
