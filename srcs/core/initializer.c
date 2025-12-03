/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:23:40 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:23:41 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_context	*initialize_context(int *values, int count)
{
	t_context	*ctx;
	int			*sorted_values;
	int			i;

	ctx = malloc(sizeof(t_context));
	if (!ctx)
		handle_error();
	sorted_values = malloc(sizeof(int) * count);
	if (!sorted_values)
	{
		free(ctx);
		handle_error();
	}
	i = -1;
	while (++i < count)
		sorted_values[i] = values[i];
	ctx->sorted_values = sorted_values;
	ctx->total_count = count;
	normalize_values(values, count, ctx);
	ctx->tower_a = create_tower('a');
	ctx->tower_b = create_tower('b');
	i = count;
	while (--i >= 0)
		add_element_top(ctx->tower_a,
			create_element(values[i], sorted_values[i]));
	free(sorted_values);
	return (ctx);
}
