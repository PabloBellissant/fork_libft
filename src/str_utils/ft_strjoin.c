/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 06:42:55 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 19:00:42 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Function that creates a new string by concataining two given in parameter.
	Will retrun NULL if allocation fails or either of two parameters is NULL.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (nul_error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = ft_calloc(sizeof(char), (s1_len + s2_len + 1));
	i = 0;
	while ((i < s1_len) && join)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while ((j < s2_len) && join)
	{
		join[i + j] = s2[j];
		j++;
	}
	return (join);
}
