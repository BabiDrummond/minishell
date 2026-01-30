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

#include "listft.h"
#include <stdlib.h>
#include <gcft.h>

t_list	*lst_new(void)
{
	t_list	*list;

	list = (t_list *)ft_malloc (sizeof(t_list));
	list->first = NULL;
	list->last = NULL;
	list->count = 0;
	return (list);
}
