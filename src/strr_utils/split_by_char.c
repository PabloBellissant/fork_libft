/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:44:00 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 17:44:05 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, bool is_char(char))
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if ((!is_char(str[i]) && is_char(str[i + 1]))
			|| (!is_char(str[i]) && str[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

static char	*strcrop(const char *str, bool is_char(char))
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str)
		return (nul_error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	i = 0;
	while (str[i] && !is_char(str[i]))
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (nul_error(0, FL, LN, FC));
	j = 0;
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

static int	populate(char **tab, const char *s, bool is_char(char))
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (!is_char(s[i]))
		{
			tab[j] = strcrop(&s[i], is_char);
			if (!tab[j])
			{
				register_complex_err_msg(LFT_E_MSG_STRCROP, &s[i], ' ');
				return (error(pack_err(LFT_ID, LFT_E_STRCROP), FL, LN, FC));
			}
			j++;
			while (!is_char(s[i]) && s[i])
				i++;
		}
		else
			i++;
	}
	return (0);
}

char	**split_by_char(const char *str, bool is_char(char))
{
	int		words;
	char	**res;

	if (!str)
		return (nul_error(pack_err(LFT_ID, LFT_E_STRNULL), FL, LN, FC));
	words = ft_count_words(str, is_char);
	res = ft_calloc(words + 1, sizeof(char *));
	if (!res)
		return (nul_error(errno, FL, LN, FC));
	if (populate(res, str, is_char) != 0)
	{
		free_strr(res);
		return (nul_error(pack_err(LFT_ID, LFT_E_STRR), FL, LN, FC));
	}
	return (res);
}
