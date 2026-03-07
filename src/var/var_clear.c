/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/src/str/ft_strncmp.c
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:53:48 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/08 02:03:54 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n || !s1 || !s2)
		return (0);
	while (n-- && (*s1 || *s2) && (*s1++ == *s2++))
		;
	return ((unsigned char)*--s1 - (unsigned char)*--s2);
========
/*   var_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:00:47 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 00:39:04 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	var_clear(void *var_content)
{
	t_var	*var;

	var = var_content;
	ft_free(&var->key);
	ft_free(&var->value);
	ft_free((char **)&var_content);
>>>>>>>> builtins:src/var/var_clear.c
}
