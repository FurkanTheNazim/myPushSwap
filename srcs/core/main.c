/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:22:35 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:22:36 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Siralama islemini baslatan fonksiyon
static void	execute_sort(t_context *ctx)
{
	t_strategy	strat;

	strat = select_strategy(ctx->total_count);
	if (strat == STRAT_TINY)
		sort_tiny(ctx);
	else if (strat == STRAT_SMALL)
		sort_small(ctx);
	else if (strat == STRAT_RADIX)
		sort_radix(ctx);
}

int	main(int argc, char **argv)
{
	int			*values;
	int			count;
	t_context	*ctx;

	values = NULL;
	count = parse_arguments(argc, argv, &values);
	if (count == 0)
		return (0);
	if (check_duplicates(values, count))
	{
		handle_error();
	}
	ctx = initialize_context(values, count);
	if (!is_stack_sorted(ctx))
		execute_sort(ctx);
	cleanup_context(ctx);
	free(values);
	return (0);
}
