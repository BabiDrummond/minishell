/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/include/types.h
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:40:46 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/12 21:09:01 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef BYTE_SIZE
#  define BYTE_SIZE 8
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

#endif
========
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:46:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 19:58:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_list **vars, char **args)
{
	int		exit_code;
	int		i;

	i = 1;
	exit_code = EXIT_SUCCESS;
	if (!args[i])
		return (exit_code);
	while (args[i])
	{
		if (!is_valid_key(args[i])
			&& printf("unset: `%s': invalid parameter name\n", args[i]))
			exit_code = EXIT_FAILURE;
		else
			var_unset(vars, args[i]);
		i++;
	}
	return (exit_code);
}
>>>>>>>> builtins:src/builtins/builtin_unset.c
