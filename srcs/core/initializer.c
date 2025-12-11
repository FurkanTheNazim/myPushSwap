/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:23:40 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/12 01:18:02 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	*allocate_sorted_values(int *values, int count, t_context *ctx)
{
	int	*sorted_values;
	int	i;

	sorted_values = malloc(sizeof(int) * count);
	if (!sorted_values)
	{
		free(ctx);
		handle_error();
	}
	i = -1;
	while (++i < count)
		sorted_values[i] = values[i];
	return (sorted_values);
}

static void	populate_tower(t_context *ctx, int *values, int *sorted, int count)
{
	int	i;

	i = count;
	while (--i >= 0)
		add_element_top(ctx->tower_a, create_element(values[i], sorted[i]));
}

t_context	*initialize_context(int *values, int count)
{
	t_context	*ctx;
	int			*sorted_values;

	ctx = malloc(sizeof(t_context));
	if (!ctx)
		handle_error();
	sorted_values = allocate_sorted_values(values, count, ctx);
	ctx->sorted_values = sorted_values;
	ctx->total_count = count;
	normalize_values(values, count, ctx);
	ctx->tower_a = create_tower('a');
	ctx->tower_b = create_tower('b');
	populate_tower(ctx, sorted_values, values, count);
	free(sorted_values);
	return (ctx);
}
