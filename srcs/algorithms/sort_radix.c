#include "pushswap.h"

void	sort_radix(t_context *ctx)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	if (!ctx || !ctx->tower_a)
		return ;
	max_bits = get_max_bits(ctx->total_count - 1);
	i = 0;
	while (i < max_bits)
	{
		size = ctx->tower_a->size;
		j = 0;
		while (j < size)
		{
			if (((ctx->tower_a->top->index >> i) & 1) == 1)
				execute_rotate_a(ctx);
			else
				execute_push_b(ctx);
			j++;
		}
		while (ctx->tower_b->size > 0)
			execute_push_a(ctx);
		i++;
	}
}
