/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:26:06 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:26:22 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse_rotate_stack(t_tower *tower)
{
	t_element	*last;
	t_element	*prev;

	if (tower->size < 2)
		return ;
	last = tower->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = tower->top;
	tower->top = last;
}

void	execute_reverse_rotate_a(t_context *ctx)
{
	reverse_rotate_stack(ctx->tower_a);
	write(1, "rra\n", 4);
}

void	execute_reverse_rotate_b(t_context *ctx)
{
	reverse_rotate_stack(ctx->tower_b);
	write(1, "rrb\n", 4);
}

void	execute_reverse_rotate_both(t_context *ctx)
{
	reverse_rotate_stack(ctx->tower_a);
	reverse_rotate_stack(ctx->tower_b);
	write(1, "rrr\n", 4);
}
