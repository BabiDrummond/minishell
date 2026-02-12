/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:39:49 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:22:12 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_print_int(t_list *head)
{
	while (head)
	{
		ft_printf("%d\n", *(int *)head->content);
		head = head->next;
	}
}
