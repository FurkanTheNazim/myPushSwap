/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:26:25 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:27:15 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate_stack(t_tower *tower)
{
	t_element	*first;
	t_element	*last;

	if (tower->size < 2)
		return ;
	first = remove_element_top(tower);
	last = tower->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	tower->size++;
}

void	execute_rotate_a(t_context *ctx)
{
	rotate_stack(ctx->tower_a);
	write(1, "ra\n", 3);
}

void	execute_rotate_b(t_context *ctx)
{
	rotate_stack(ctx->tower_b);
	write(1, "rb\n", 3);
}

void	execute_rotate_both(t_context *ctx)
{
	rotate_stack(ctx->tower_a);
	rotate_stack(ctx->tower_b);
	write(1, "rr\n", 3);
}
