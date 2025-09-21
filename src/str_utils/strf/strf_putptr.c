/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf_putptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:47:58 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/21 15:56:07 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strf_putptr(char *output, size_t len, long unsigned int ptr)
{
	size_t	write_len;

	write_len = 0;
	if (!ptr)
		return (strf_putstr(output, len, PTR_NIL));
	else
	{
		write_len += strf_putstr(output, len, HEX_PREFIX);
		len -= write_len;
		if (len > 0)
			write_len += strf_puthex(output + write_len, len, ptr, false);
	}
	return (write_len);
}
