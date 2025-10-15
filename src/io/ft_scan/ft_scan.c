/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <pabellis@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 00:11:43 by pabellis          #+#    #+#             */
/*   Updated: 2025/08/07 09:32:13 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "lft_xcerrcal.h"

static void			skip_wildcard(const char **line, char char_to_skip);
int					parse_type(va_list *args, const char **line, int line_num, const char *format);
static int			verif_char(const char *format, const char **line, int line_num);
static const char	*skip_range(const char *format);

void	scan_optional_arg(va_list *args, const char **format, const char **line)
{
	va_list	copy;
	const char	*line_backup;

	line_backup = *line;
	++*format;
	va_copy(copy, *args);
	while (**format && **format != ')')
	{
		if ((*format)[0] && (*format)[1] == '*')
		{
			skip_wildcard(line, **format);
			++*format;
		}
		else if (**format == '%')
		{
			++*format;
			if (parse_type(&copy, line, -1, *format) == -1)
			{
				*line = line_backup;
				break ;
			}
			*format = skip_range(*format);
		}
		else if (verif_char(*format, line, -1) == -1)
		{
			*line = line_backup;
			break ;
		}
		++*format;
	}
	*format = ft_strchr(*format, ')') + 1;
}

int	ft_scan(int line_num, const char *format, const char *line, ...)
{
	va_list		args;

	va_start(args, line);
	while (*format)
	{
		if (format[0] == '(')
			scan_optional_arg(&args, &format, &line);
		if (format[0] && format[1] == '*')
		{
			skip_wildcard(&line, *format);
			++format;
		}
		else if (*format == '%')
		{
			++format;
			if (parse_type(&args, &line, line_num, format) == -1)
				return (-1);
			format = skip_range(format);
		}
		else if (verif_char(format, &line, line_num) == -1)
			return (-1);
		++format;
	}
	return (0);
}

static const char	*skip_range(const char *format)
{
	if (format[1] == '[')
		format = ft_strchr(format, ']');
	return (format);
}

static int	verif_char(const char *format, const char **line, int line_num)
{
	if (*format != **line && !(**line == '\0' && *format == '\n')
		&& !(ft_isspace(*format) && ft_isspace(**line)))
	{
		if (line_num == -1)
			return (-1);
		register_complex_err_msg(LFT_E_MSG_WRN_CHAR, **line, *format);
		return (error(pack_err(LFT_ID, LFT_E_WRN_CHAR), FL, LN, FC));
	}
	++*line;
	return (0);
}

static void	skip_wildcard(const char **line, const char char_to_skip)
{
	while (**line == char_to_skip
		|| (ft_isspace(char_to_skip) && ft_isspace(**line)))
		++*line;
}
