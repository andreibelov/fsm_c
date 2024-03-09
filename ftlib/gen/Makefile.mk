# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 02:54:03 by abelov            #+#    #+#              #
#    Updated: 2023/12/16 02:54:06 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES   = ft_isctype.c \
           ft_dlst1.c \
           ft_dlst2.c \
           ft_dlst3.c \
           ft_lst1.c \
           ft_lst2.c
SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)
