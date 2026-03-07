/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/src/str/ft_strjoin_free.c
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:11:29 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:17:35 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (ft_free(&s1), ft_free(&s2), NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new[i++] = s2[j++];
	if (free_s1)
		ft_free(&s1);
	if (free_s2)
		ft_free(&s2);
	return (new);
========
/*   var_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:31:44 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:26:25 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*var_get(t_list *vars, char *key)
{
	t_var	*curr_var;

	if (!vars || !key)
		return (NULL);
	while (vars)
	{
		curr_var = (t_var *) vars->content;
		if (curr_var && curr_var->key && !ft_strcmp(curr_var->key, key))
			return (curr_var);
		vars = vars->next;
	}
	return (NULL);
}

char	*var_get_value(t_list *vars, char *key)
{
	t_var	*var;

	var = var_get(vars, key);
	if (var)
		return (var->value);
	return (NULL);
>>>>>>>> builtins:src/var/var_get.c
}
