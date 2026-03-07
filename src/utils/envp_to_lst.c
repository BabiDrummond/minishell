/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:libft/src/str/ft_join_split.c
/*   ft_join_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:58:49 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/19 17:51:54 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_join_split(char **split, char *separator)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	str = ft_strdup("");
	if (!split || !*split)
		return (str);
	size = ft_split_size(split);
	while (i < size)
	{
		str = ft_strjoin_free(str, split[i], TRUE, FALSE);
		if (i < size - 1)
			str = ft_strjoin_free(str, separator, TRUE, FALSE);
		i++;
	}
	return (str);
========
/*   envp_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:55:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/05 21:55:00 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*envp_to_lst(char **envp)
{
	t_list	*vars;
	t_var	*var;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	vars = NULL;
	while (envp[i])
	{
		key = extract_key(envp[i]);
		value = extract_value(envp[i]);
		var = var_create(key, value, TRUE);
		lst_add_back(&vars, lst_new(var));
		i++;
	}
	return (vars);
>>>>>>>> builtins:src/utils/envp_to_lst.c
}
