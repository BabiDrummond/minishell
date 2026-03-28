/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcosta-b <bcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:42:32 by bmoreira          #+#    #+#             */
/*   Updated: 2026/03/28 03:16:40 by bcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static long long	exit_atoll(t_shell *ctx, char *ascii)
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
			return (exit_status(ctx, SYNTAX_ERROR, FALSE));
		else if (num > LLONG_MAX / 10 || (num == LLONG_MAX / 10 && ((sign == 1
						&& *ascii > '7') || (sign == -1 && *ascii > '8'))))
			return (exit_status(ctx, SYNTAX_ERROR, FALSE));
		num = (num * 10) + *ascii - '0';
		ascii++;
	}
	return (num * sign);
}

int	exit_status(t_shell *ctx, int exit_code, int should_exit)
{
	ctx->exit_status = exit_code;
	ctx->should_exit = should_exit;
	return (ctx->exit_status);
}

int	builtin_exit(t_shell *ctx, char **argv)
{
	long long	exit_code;

	if (!argv[1])
	{
		printf("exit");
		gc_exit(ctx->exit_status);
	}
	exit_code = exit_atoll(ctx, argv[1]);
	if (ctx->exit_status == SYNTAX_ERROR)
	{
		ft_putstr_fd(ft_replace("exit\nexit: %s: numeric argument required\n", "%s", argv[1]), 2);
		gc_exit(SYNTAX_ERROR);
	}
	if (ft_split_size(argv) > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (exit_status(ctx, EXIT_FAILURE, FALSE));
	}
	if (exit_code < 0 || exit_code > 255)
	{
		printf("exit");
		gc_exit((unsigned char) exit_code);
	}
	return (ctx->exit_status);
}
