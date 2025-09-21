/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:47:57 by jaubry--          #+#    #+#             */
/*   Updated: 2025/09/21 15:56:02 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strf_recu_putnbr(char *output, size_t len, long int nb)
{
	size_t	write_len;

	write_len = 0;
	if ((nb > 0) && (len > 0))
	{
		write_len = 1 + strf_recu_putnbr(output, len - 1, nb / 10);
		output[write_len - 1] = (nb % 10) + '0';
	}
	return (write_len);
}

size_t	strf_putnbr(char *output, size_t len, long int nb)
{
	size_t	write_len;

	write_len = 0;
	if ((nb < 0) && (len > 0))
	{
		output[write_len] = '-';
		nb = -nb;
		write_len++;
		len--;
	}
	if ((nb == 0) && (len > 0))
	{
		output[write_len] = '0';
		write_len++;
		len--;
	}
	else
		write_len += strf_recu_putnbr(output + write_len, len, nb);
	return (write_len);
}
