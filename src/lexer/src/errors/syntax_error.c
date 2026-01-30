/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:48:46 by bcosta-b          #+#    #+#             */
/*   Updated: 2026/01/29 18:22:17 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "gcft.h"

void	syntax_error(void)
{
	printf("Syntax Error: Unclosed quote\n");
	gc_free_all();
	exit(1);
}
