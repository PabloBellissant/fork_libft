/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:12:47 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 15:08:00 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strrlen(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

void	free_strr(char **strs)
{
	size_t	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
	{
		ft_free(strs[i]);
		i++;
	}
	ft_free(strs);
}

void	free_strr_fail(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (strs && strs[i] && (i < size))
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_strrdup(char **strs)
{
	char	**new;
	size_t	i;

	if (!strs)
		return (NULL);
	i = 0;
	new = ft_calloc(ft_strrlen(strs) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		if (!new[i])
			return (free_strr_fail(new, i), NULL);
		i++;
	}
	return (new);
}

int	strr_add(char ***strs, char *str)
{
	char	**new;
	size_t	i;

	i = 0;
	if (!strs || !*strs)
		return (1);
	new = ft_calloc(ft_strrlen(*strs) + 2, sizeof(char *));
	if (!new)
		return (1);
	while ((*strs)[i])
	{
		new[i] = ft_strdup((*strs)[i]);
		if (!new[i])
			return (free_strr_fail(new, i), 1);
		i++;
	}
	new[i] = ft_strdup(str);
	if (!new[i])
		return (free_strr_fail(new, i), 1);
	free_strr(*strs);
	*strs = new;
	return (0);
}
