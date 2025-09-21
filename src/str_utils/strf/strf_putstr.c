/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:48:00 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/21 15:55:50 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strf_putstr(char *output, const size_t len, const char *str)
{
	size_t	str_len;

	if (str == NULL)
		return (strf_putstr(output, len, STR_NULL));
	str_len = ft_strlen(str);
	if (str_len > len)
	{
		ft_memcpy(output, str, len);
		return (len);
	}
	else
	{
		ft_memcpy(output, str, str_len);
		return (str_len);
	}
}
