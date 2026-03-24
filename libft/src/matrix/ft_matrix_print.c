/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:00:01 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/23 22:50:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	ft_matrix_print(char **matrix)
{
	while (matrix && *matrix)
		printf("%s\n", *matrix++);
}
