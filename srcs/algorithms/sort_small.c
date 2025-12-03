/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:24:54 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:24:54 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	find_min_index(t_tower *tower)
{
	t_element	*curr;
	int			min;

	if (!tower || !tower->top)
		return (-1);
	curr = tower->top;
	min = curr->index;
	while (curr)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}

static int	get_position(t_tower *tower, int target_index)
{
	t_element	*curr;
	int			pos;

	curr = tower->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target_index)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (-1);
}

static void	push_min_to_b(t_context *ctx)
{
	int	min_idx;
	int	pos;
	int	size;

	min_idx = find_min_index(ctx->tower_a);
	pos = get_position(ctx->tower_a, min_idx);
	size = ctx->tower_a->size;
	if (pos <= size / 2)
	{
		while (ctx->tower_a->top->index != min_idx)
			execute_rotate_a(ctx);
	}
	else
	{
		while (ctx->tower_a->top->index != min_idx)
			execute_reverse_rotate_a(ctx);
	}
	execute_push_b(ctx);
}

void	sort_small(t_context *ctx)
{
	if (!ctx || !ctx->tower_a)
		return ;
	while (ctx->tower_a->size > 3)
		push_min_to_b(ctx);
	sort_tiny(ctx);
	while (ctx->tower_b->size > 0)
		execute_push_a(ctx);
}
