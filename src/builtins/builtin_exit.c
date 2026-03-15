/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:42:32 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/14 22:20:41 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

long long	exit_atoll(t_shell *ctx, char *ascii)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*ascii))
		ascii++;
	if (*ascii == '-' || *ascii == '+')
		if (*ascii++ == '-')
			sign *= -1;
	while (*ascii)
	{
		if (!ft_isdigit(*ascii))
			ctx->exit_status = SYNTAX_ERROR;
		else if (num > LLONG_MAX / 10 || (num == LLONG_MAX / 10 && ((sign == 1
						&& *ascii > '7') || (sign == -1 && *ascii > '8'))))
			ctx->exit_status = SYNTAX_ERROR;
		else
			num = (num * 10) + *ascii - '0';
		ascii++;
	}
	return (num * sign);
}

int	builtin_exit(t_shell *ctx, char **argv)
{
	long long	exit_code;

	printf("exit\n");
	if (!argv[1])
		exit(ctx->exit_status);
	exit_code = exit_atoll(ctx, argv[1]);
	if (ctx->exit_status == SYNTAX_ERROR
		&& printf("exit: %s: numeric argument required\n", argv[1]))
		exit(SYNTAX_ERROR);
	if (ft_split_size(argv) > 2 && printf("exit: too many arguments\n"))
		return (EXIT_FAILURE);
	if (exit_code < 0 || exit_code > 255)
		exit_code = exit_code % 256;
	exit(exit_code);
}
