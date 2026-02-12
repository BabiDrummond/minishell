/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:12:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/18 17:21:30 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	lst_add_back(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_last(*lst)->next = new;
}
