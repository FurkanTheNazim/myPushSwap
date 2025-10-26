#include "pushswap.h"

static t_strategy	select_strategy(int count)
{
	if (count <= 3)
		return (STRAT_TINY);
	if (count <= 5)
		return (STRAT_SMALL);
	return (STRAT_RADIX);
}

t_context	*initialize_context(int *values, int count)
{
	t_context *ctx;
	int	*i;
	int	j;

	ctx = malloc(sizeof(t_context));
	if (!ctx)
		handle_error();
	i = malloc(sizeof(int) * count);
	if (!i)
	{
		free(ctx);
		handle_error();
	}
	j = 0;
	while (j < count)
	{
		i[j] = values[j];
		j++;
	}
	normalize_values(values, count, ctx);
	ctx->tower_a = create_tower('a');
	ctx->tower_b = create_tower('b');
	j = count - 1;
	while (j >= 0)
	{
		t_element *el = create_element(i[j], values[j]);
		add_element_top(ctx->tower_a, el);
		j--;
	}
	ctx->total_count = count;
	free(i);
	return (ctx);
}
