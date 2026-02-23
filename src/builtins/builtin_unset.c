/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 00:46:16 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/23 01:55:47 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_valid_key(char *var_content)
{
	int	i;

	i = 1;
	if (!ft_isalpha(var_content[0]) && !(var_content[0] == '_'))
		return (FALSE);
	while (ft_isalnum(var_content[i]) || var_content[i] == '_')
		i++;
	return (var_content[i] == '\0');
}

void	builtin_unset(t_list **vars, char *content)
{
	char	**split;
	int		i;

	i = 0;
	if (!ft_strlen(content))
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	split = ft_split(content, ' ');
	while (split[i])
	{
		if (!is_valid_key(split[i]))
			printf("unset: invalid parameter name\n");
		else
			var_unset(vars, split[i]);
		i++;
	}
	ft_split_free(split);
}



// unset => vazio, erro not enough arguments
// unset VAR-JAS => invalido, erro parametro invalido
// unset VAR => valido, procura VAR, se nao tiver, nao faz nada
// unset VAR => valido, procura VAR, se tiver, deleta da lista