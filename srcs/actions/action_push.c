/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:25:55 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:26:05 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	execute_push_a(t_context *ctx)
{
	t_element	*elem;

	if (!ctx->tower_b || !ctx->tower_b->top)
		return ;
	elem = remove_element_top(ctx->tower_b);
	add_element_top(ctx->tower_a, elem);
	write(1, "pa\n", 3);
}

void	execute_push_b(t_context *ctx)
{
	t_element	*elem;

	if (!ctx->tower_a || !ctx->tower_a->top)
		return ;
	elem = remove_element_top(ctx->tower_a);
	add_element_top(ctx->tower_b, elem);
	write(1, "pb\n", 3);
}
