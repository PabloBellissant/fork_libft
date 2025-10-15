/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_xcerrcal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:38:46 by jaubry--          #+#    #+#             */
/*   Updated: 2025/10/09 15:09:21 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_XCERRCAL_H
# define LFT_XCERRCAL_H

#define LFT_ID 2

typedef enum e_lft_err
{
    LFT_E_TIME = 1,
    LFT_E_SPLIT,
    LFT_E_STRNULL,
    LFT_E_STRR,
    LFT_E_STRCROP,
    LFT_E_STRDUP,
    LFT_E_STRRDUP,
    LFT_E_STRADD,
    LFT_E_STRJOIN,
    LFT_E_STRTRIM,
    LFT_E_SUBSTR,
    LFT_E_GNL,
    LFT_E_CRITGNL,
    LFT_E_VEC_RESIZE,
    LFT_E_VEC_ADD,
    LFT_E_VEC_REALLOC,
    LFT_E_CALC_S,
    LFT_E_REALLOC,
    LFT_E_NOT_FLT,
    LFT_E_NOT_INT,
    LFT_E_FLT_RANGE,
    LFT_E_INT_RANGE,
    LFT_E_WRN_CHAR,
    LFT_ERRS_NUM
}	t_lft_err;

#define LFT_E_MSG_TIME "Time retriaval failed"
#define LFT_E_MSG_SPLIT "Split string \"%s\" using delimiter `%c` failed"
#define LFT_E_MSG_STRNULL "String passed is NULL"
#define LFT_E_MSG_STRR "Failed to populate array of strings"
#define LFT_E_MSG_STRCROP "Cropping string \"%s\" using delimiter `%c` failed"
#define LFT_E_MSG_STRDUP "String duplication failed"
#define LFT_E_MSG_STRRDUP "Array of strings duplication failed"
#define LFT_E_MSG_STRADD "Appending string array failed"
#define LFT_E_MSG_STRJOIN "Join strings failed"
#define LFT_E_MSG_STRTRIM "Trim string failed"
#define LFT_E_MSG_SUBSTR "Substring extraction failed"
#define LFT_E_MSG_GNL "Could not get next line"
#define LFT_E_MSG_CRITGNL "Invalid BUFFER_SIZE or wrong fd"
#define LFT_E_MSG_VEC_RESIZE "Could not resize vector"
#define LFT_E_MSG_VEC_ADD "Could not add element to vector"
#define LFT_E_MSG_VEC_REALLOC "Could not realloc vector"
#define LFT_E_MSG_CALC_S "Invalid calloc size"
#define LFT_E_MSG_REALLOC "Could not realloc %d to %d at adress %p"

#define LFT_E_MSG_NOT_FLT "Invalid float, line: %d"
#define LFT_E_MSG_NOT_INT "Invalid integer, line: %d"
#define LFT_E_MSG_FLT_RANGE "Float not in range [%d:%d], line: %d"
#define LFT_E_MSG_INT_RANGE "Integer not in range [%d:%d], line: %d"
#define LFT_E_MSG_WRN_CHAR "`%c` is not a valid character, expecting `%c`"

void	register_lft_errors(void);

#endif//LFT_XCERRCAL_H
