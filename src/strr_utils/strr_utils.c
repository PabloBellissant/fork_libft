/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strr_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:12:47 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 19:02:02 by jaubry--         ###   ########.fr       */
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

bool	free_strr_fail(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (strs && strs[i] && (i < size))
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (true);
}

char	**ft_strrdup(char **strs)
{
	char	**new;
	size_t	i;

	if (!strs)
		return (nul_error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	i = 0;
	new = ft_calloc(ft_strrlen(strs) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		if (!new[i] && free_strr_fail(new, i))
			return (nul_error(pack_err(LFT_ID, LFT_E_STRDUP), FL, LN, FC));
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
		return (error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	new = ft_calloc(ft_strrlen(*strs) + 2, sizeof(char *));
	if (!new)
		return (1);
	while ((*strs)[i])
	{
		new[i] = ft_strdup((*strs)[i]);
		if (!new[i] && free_strr_fail(new, i))
			return (error(pack_err(LFT_ID, LFT_E_STRDUP), FL, LN, FC));
		i++;
	}
	new[i] = ft_strdup(str);
	if (!new[i] && free_strr_fail(new, i))
		return (error(pack_err(LFT_ID, LFT_E_STRDUP), FL, LN, FC));
	free_strr(*strs);
	*strs = new;
	return (0);
}
