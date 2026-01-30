/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:24:35 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/30 18:29:03 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gcft.h"

t_list	*get_collector(void)
{
	static t_list	collector = {NULL, NULL, 0};

	return (&collector);
}
