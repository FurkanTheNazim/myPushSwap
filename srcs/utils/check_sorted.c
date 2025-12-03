/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:18:08 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:18:10 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_stack_sorted(t_context *ctx)
{
	t_element	*current;

	if (!ctx || !ctx->tower_a || !ctx->tower_a->top)
		return (1);
	current = ctx->tower_a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
