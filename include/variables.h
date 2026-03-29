/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 23:26:35 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 23:28:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include "../libft/include/libft.h"

typedef struct s_var
{
	char	*key;
	char	*value;
	int		exported;
}	t_var;

/* Variables */
t_var	*var_create(char *key, char *value, int exported);
t_var	*var_get(t_list *vars, char *key);
char	*var_get_value(t_list *vars, char *key);
int		var_set(t_list **vars, char *key, char *value, int exported);
void	var_unset(t_list **vars, char *key);
void	var_update(t_list **vars, t_var *var);

/* Utils */
char	*extract_key(char *var_content);
char	*extract_value(char *var_content);
int		is_valid_key(char *var_content);

#endif