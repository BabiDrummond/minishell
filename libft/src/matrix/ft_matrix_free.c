/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:43:14 by bmoreira          #+#    #+#             */
/*   Updated: 2025/12/04 19:04:50 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

char	**ft_matrix_free(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !*matrix)
		return (NULL);
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (NULL);
}
