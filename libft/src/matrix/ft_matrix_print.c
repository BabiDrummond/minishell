/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/src/matrix/ft_matrix_print.c
/*   ft_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:00:01 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 04:09:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	ft_matrix_print(char **matrix)
{
	while (*matrix)
		printf("%s\n", *matrix++);
}
========
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:10:41 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 00:42:27 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>

void	ft_matrix_print(char **matrix);

#endif
>>>>>>>> builtins:libft/include/matrix.h
