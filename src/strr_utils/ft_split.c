/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarcucc <lucas@student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:03:56 by lmarcucc          #+#    #+#             */
/*   Updated: 2025/10/09 17:54:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, int c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] == c)
			|| (str[i] != c && str[i + 1] == 0))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static int	populate(char **tab, const char *s, int sep)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != sep)
		{
			tab[j] = ft_strcrop(&s[i], sep);
			if (!tab[j])
			{
				register_complex_err_msg(LFT_E_MSG_STRCROP, &s[i], sep);
				return (error(pack_err(LFT_ID, LFT_E_STRCROP), FL, LN, FC));
			}
			j++;
			while ((s[i] != sep) && s[i])
				i++;
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(const char *str, int c)
{
	int		words;
	char	**res;

	if (!str)
		return (nul_error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	words = ft_count_words(str, c);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (nul_error(errno, FL, LN, FC));
	if (populate(res, str, c) != 0)
	{
		free_strr(res);
		return (nul_error(pack_err(LFT_ID, LFT_E_STRR), FL, LN, FC));
	}
	return (res);
}
