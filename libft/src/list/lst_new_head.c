/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:41:00 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/27 02:33:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_head	*lst_new_head(void)
{
	t_head	*list;

	list = (t_head *)safe_calloc(1, sizeof(t_head));
	list->first = NULL;
	list->last = NULL;
	list->count = 0;
	return (list);
}
