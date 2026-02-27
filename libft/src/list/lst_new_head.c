/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:41:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:31:43 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_head	*lst_new_head(void)
{
	t_head	*list;

	list = (t_head *)ft_calloc(1, sizeof(t_head));
	list->first = NULL;
	list->last = NULL;
	list->count = 0;
	return (list);
}
