/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:24:35 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/03/28 01:26:02 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	gc_exit(int exit_status)
{
	gc_set_current_scope(GC_SCOPE_FUNCTION);
	gc_free_all();
	gc_free_all();
	exit(exit_status);
}
