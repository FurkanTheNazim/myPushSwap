/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:20:30 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:21:01 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	add_element_top(t_tower *tower, t_element *elem)
{
	if (!tower || !elem)
		return ;
	elem->next = tower->top;
	tower->top = elem;
	tower->size += 1;
}

t_element	*remove_element_top(t_tower *tower)
{
	t_element	*el;

	if (!tower || !tower->top)
		return (NULL);
	el = tower->top;
	tower->top = el->next;
	tower->size -= 1;
	el->next = NULL;
	return (el);
}

void	cleanup_context(t_context *ctx)
{
	if (!ctx)
		return ;
	destroy_tower(ctx->tower_a);
	destroy_tower(ctx->tower_b);
	if (ctx->sorted_values)
		free(ctx->sorted_values);
	free(ctx);
}
