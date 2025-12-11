/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:25:27 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/12 01:12:44 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_three(t_context *ctx)
{
	int	a;
	int	b;
	int	c;

	if (is_stack_sorted(ctx))
		return ;
	a = ctx->tower_a->top->index;
	b = ctx->tower_a->top->next->index;
	c = ctx->tower_a->top->next->next->index;
	if (a > b && b < c && a < c)
		execute_swap_a(ctx);
	else if (a > b && b > c)
	{
		execute_swap_a(ctx);
		execute_reverse_rotate_a(ctx);
	}
	else if (a > b && b < c && a > c)
		execute_rotate_a(ctx);
	else if (a < b && b > c && a < c)
	{
		execute_swap_a(ctx);
		execute_rotate_a(ctx);
	}
	else if (a < b && b > c && a > c)
		execute_reverse_rotate_a(ctx);
}

void	sort_tiny(t_context *ctx)
{
	if (!ctx || !ctx->tower_a)
		return ;
	if (ctx->tower_a->size == 2)
	{
		if (ctx->tower_a->top->index > ctx->tower_a->top->next->index)
			execute_swap_a(ctx);
	}
	else if (ctx->tower_a->size == 3)
		sort_three(ctx);
}
