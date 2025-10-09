# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    srcs.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/09 12:56:17 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/09 12:59:05 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MKs
MKS			= io/io.mk alloc/alloc.mk parsing/parsing.mk \
			  conversion/conversion.mk mem_utils/mem_utils.mk \
			  str_utils/str_utils.mk strr_utils/strr_utils.mk \
			  data_structs/data_structs.mk utils/utils.mk
include $(addprefix $(SRCDIR)/, $(MKS))

SRCS		+= register_lft_errors.c

vpath %.c $(SRCDIR)
