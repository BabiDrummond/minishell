/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:12:46 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/09 20:31:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listft.h"

void	lst_delete(t_list *lst, void (*free_content)(void*))
{
	lst_delete_all(lst, free_content);
	free(lst);
}
