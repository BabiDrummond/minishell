/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:34:24 by bmoreira          #+#    #+#             */
/*   Updated: 2026/02/22 23:17:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    builtin_cd(t_shell *shell)
{

}

// cd (empty args) => changes to home
// cd . => stays on current dir
// cd .. => changes to previous dir
// cd ~ => changes to home
// cd / (one or more slashes) => changes to root
// cd /(one or more slashes)dirname => changes to folder in root
// cd ex/dir => check if exists. if yes, change to dir. if not, shows error msg\