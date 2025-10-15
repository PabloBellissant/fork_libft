/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_lft_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:41:05 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 15:10:51 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xcerrcal.h"
#include "lft_xcerrcal.h"

void	register_lft_errors(void)
{
	const char	*err_msgs[] =
	{
		LFT_E_MSG_TIME,
		LFT_E_MSG_SPLIT,
		LFT_E_MSG_STRNULL,
		LFT_E_MSG_STRR,
		LFT_E_MSG_STRCROP,
		LFT_E_MSG_STRDUP,
		LFT_E_MSG_STRRDUP,
		LFT_E_MSG_STRADD,
		LFT_E_MSG_STRJOIN,
		LFT_E_MSG_STRTRIM,
		LFT_E_MSG_SUBSTR,
		LFT_E_MSG_GNL,
		LFT_E_MSG_CRITGNL,
		LFT_E_MSG_VEC_RESIZE,
		LFT_E_MSG_VEC_ADD,
		LFT_E_MSG_VEC_REALLOC,
		LFT_E_MSG_CALC_S,
		LFT_E_MSG_REALLOC,
		LFT_E_MSG_NOT_FLT,
		LFT_E_MSG_NOT_INT,
		LFT_E_MSG_FLT_RANGE,
		LFT_E_MSG_INT_RANGE,
		LFT_E_MSG_WRN_CHAR
	};
	bulk_register_error(LFT_ERRS_NUM - 1, LFT_ID, (const char **)err_msgs);
}
