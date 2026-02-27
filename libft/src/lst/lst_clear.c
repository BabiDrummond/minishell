/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:19:04 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 16:53:10 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_clear(t_list **head, void (*del)(void *))
{
	t_list	*next;

	if (!head)
		return ;
	while (*head)
	{
		next = (*head)->next;
		lst_clear_node(*head, (*del));
		*head = next;
	}
	*head = NULL;
}
