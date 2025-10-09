/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 08:27:09 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 19:09:20 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Function that allocates len * size bytes using malloc.
	Protect from overflowing and sets mem allocated to 0
*/
void	*ft_calloc(size_t len, size_t size)
{
	size_t	bytes;
	void	*alloc;

	bytes = len * size;
	if (((bytes != 0) && ((bytes < len) || (bytes < size))))
		return (nul_error(pack_err(LFT_ID, LFT_E_CALC_S), FL, LN, FC));
	alloc = malloc(bytes);
	if (!alloc)
		return (NULL);
	return (ft_fbzero(alloc, bytes));
}
