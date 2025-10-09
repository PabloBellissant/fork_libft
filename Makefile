# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 01:19:17 by jaubry--          #+#    #+#              #
#    Updated: 2025/10/09 19:32:27 by jaubry--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOTDIR		?= .
include $(ROOTDIR)/mkidir/make_utils.mk

# Directories
CDIR		= libft
SRCDIR		= src
INCDIR		= include
OBJDIR		= .obj
DEPDIR		= .dep

XCERRCALDIR	= $(LIBDIR)/xcerrcal

# Output
NAME		= libft.a
XCERRCAL	= $(XCERRCALDIR)/libxcerrcal.a


# Compiler and flags
CC			= cc

CFLAGS		= -Wall -Wextra -Werror

DFLAGS		= -MMD -MP -MF $(DEPDIR)/$*.d

IFLAGS		= -I$(INCDIR) -I$(XCERRCALDIR)/include

LFLAGS		= -L$(XCERRCALDIR) -lxcerrcal

VARS		= DEBUG=$(DEBUG)
VFLAGS		= $(addprefix -D ,$(VARS))

CFLAGS		+= $(DEBUG_FLAGS) $(FFLAGS) $(VFLAGS)
CF			= $(CC) $(CFLAGS) $(IFLAGS)

AR          = $(if $(findstring -flto,$(FFLAGS)),$(FAST_AR),$(STD_AR))
ARFLAGS		= rcs
RANLIB      = $(if $(findstring -flto,$(FFLAGS)),$(FAST_RANLIB),$(STD_RANLIB))

# VPATH
vpath %.h $(INCDIR) $(XCERRCALDIR)/$(INCDIR)
vpath %.o $(OBJDIR) $(XCERRCALDIR)/$(OBJDIR)
vpath %.d $(DEPDIR) $(XCERRCALDIR)/$(DEPDIR)

# Sources
include $(SRCDIR)/srcs.mk

OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(DEPDIR)/, $(notdir $(SRCS:.o=.d)))



all:	$(NAME)
fast:	$(NAME)
debug:	$(NAME)

$(NAME): $(XCERRCAL) $(OBJS)
	$(call ar-msg)
	@$(AR) $(ARFLAGS) $@ $^
ifeq ($(FAST),1)
	@$(RANLIB) $@
endif
	$(call ar-finish-msg)

$(XCERRCAL):
	@$(MAKE) -s -C $(XCERRCALDIR) $(RULE) $(VARS) ROOTDIR=../..

$(OBJDIR)/%.o: %.c | buildmsg $(OBJDIR) $(DEPDIR)
	$(call lib-compile-obj-msg)
	@$(CF) $(DFLAGS) -c $< -o $@

$(OBJDIR) $(DEPDIR):
	$(call create-dir-msg)
	@mkdir -p $@

buildmsg:
ifneq ($(shell [ -f $(NAME) ] && echo exists),exists)
	$(call lib-build-msg)
endif

help:
	@echo "Available targets:"
	@echo "  all     : Build the library"
	@echo "  clean   : Remove object files"
	@echo "  fclean  : Remove object files and library"
	@echo "  re      : Rebuild everything"

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

clean:
	@$(MAKE) -s -C $(XCERRCALDIR) clean ROOTDIR=../..
	$(call rm-obj-msg)
	@rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	@$(MAKE) -s -C $(XCERRCALDIR) fclean ROOTDIR=../..
	$(call rm-lib-msg)
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re debug help buildmsg print-%
