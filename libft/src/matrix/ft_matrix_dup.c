/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:56:45 by bmoreira          #+#    #+#             */
/*   Updated: 2025/10/29 21:11:19 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

char	**ft_matrix_dup(char **matrix)
{
	char	**new;
	int		row;
	int		col;

	row = -1;
	new = ft_calloc(ft_matrix_len(matrix) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (matrix[++row])
	{
		col = -1;
		new[row] = ft_calloc(ft_strlen(matrix[row]) + 1, sizeof(char));
		if (!new[row])
			return (NULL);
		while (matrix[row][++col])
			new[row][col] = matrix[row][col];
	}
	return (new);
}
