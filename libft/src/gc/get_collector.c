/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:24:35 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/02/04 15:14:00 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

t_gc_scope	*gc_get_current_scope(void)
{
	static t_gc_scope	current_scope = GC_SCOPE_GLOBAL;

	return (&current_scope);
}

void	gc_set_current_scope(t_gc_scope new_scope)
{
	t_gc_scope	*current_scope;

	current_scope = gc_get_current_scope();
	*current_scope = new_scope;
}

t_head	*get_collector(void)
{
	static t_head	collector[GC_SCOPE_COUNT] = {0};

	return (&collector[*gc_get_current_scope()]);
}
