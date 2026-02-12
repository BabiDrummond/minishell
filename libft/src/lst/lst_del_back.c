/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:20:57 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:21:45 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_del_back(t_list **head, void (*del)(void *))
{
	t_list	*temp;

	if (!head || !*head)
		return ;
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	lst_del_node(temp->next, (*del));
	temp->next = NULL;
}
