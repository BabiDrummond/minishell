/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:29:30 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:29:31 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcft.h"

void	gc_add(void *ptr, void (*destructor)(void *))
{
	lst_add_last(get_collector(), (t_node *)create_gc_node(ptr, destructor));
}
