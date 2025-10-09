/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 00:06:47 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 15:10:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include "xcerrcal.h"
#include "lft_xcerrcal.h"

ssize_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (neg_error(pack_err(LFT_ID, LFT_E_TIME), FL, LN, FC));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
