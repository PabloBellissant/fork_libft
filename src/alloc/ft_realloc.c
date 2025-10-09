/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:44:27 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/10/09 19:09:45 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *pnt, size_t old_size, size_t size)
{
	void	*new;

	if (size == 0)
		return (NULL);
	new = ft_calloc(1, size);
	if (!new)
		return (NULL);
	if (!pnt)
		return (new);
	new = ft_memcpy(new, pnt, old_size);
	return (new);
}
