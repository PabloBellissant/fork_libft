/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:19:45 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/10/09 17:53:56 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcrop(const char *str, int c)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str)
		return (nul_error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
