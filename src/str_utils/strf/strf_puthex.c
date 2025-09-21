/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf_puthex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:47:52 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/21 15:55:57 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strf_recu_puthex(char *output, size_t len,
		long unsigned int nb, char *charset)
{
	size_t	write_len;

	write_len = 0;
	if ((nb > 0) && (len > 0))
	{
		write_len = 1 + strf_recu_puthex(output, len - 1, nb / 16, charset);
		output[write_len - 1] = charset[nb % 16];
	}
	return (write_len);
}

/*
	Currently does not support negative values
*/
size_t	strf_puthex(char *output, size_t len, long unsigned int nb, bool maj)
{
	char	charset[16];
	size_t	write_len;

	if (maj)
		ft_memcpy(charset, HEX_MAJ, 16);
	else
		ft_memcpy(charset, HEX_MIN, 16);
	write_len = 0;
	if ((nb == 0) && (len > 0))
	{
		output[write_len] = '0';
		write_len++;
		len--;
	}
	else
		write_len += strf_recu_puthex(output + write_len, len, nb, charset);
	return (write_len);
}
