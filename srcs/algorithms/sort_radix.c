#include "pushswap.h"

// Radix Sort algoritmasi (Taban siralamasi)
// Sayilari bitlerine gore siralar (ikilik tabanda)
static void	process_radix_bit(t_context *ctx, int bit_idx, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((ctx->tower_a->top->index >> bit_idx) & 1) == 1)
			execute_rotate_a(ctx);
		else
			execute_push_b(ctx);
		j++;
	}
}

void	sort_radix(t_context *ctx)
{
	int	max_bits;
	int	i;

	if (!ctx || !ctx->tower_a)
		return ;
	max_bits = get_max_bits(ctx->total_count - 1);
	i = 0;
	while (i < max_bits)
	{
		process_radix_bit(ctx, i, ctx->tower_a->size);
		while (ctx->tower_b->size > 0)
			execute_push_a(ctx);
		i++;
	}
}
