#include "pushswap.h"

// Yiginindaki ilk iki elemani takas et
static void	swap_stack(t_tower *tower)
{
	t_element	*first;
	t_element	*second;

	if (tower->size < 2)
		return ;
	first = remove_element_top(tower);
	second = remove_element_top(tower);
	add_element_top(tower, first);
	add_element_top(tower, second);
}

// sa: A yiginindaki ilk iki elemani takas et
void	execute_swap_a(t_context *ctx)
{
	swap_stack(ctx->tower_a);
	write(1, "sa\n", 3);
}

// sb: B yiginini ilk iki elemani takas et
void	execute_swap_b(t_context *ctx)
{
	swap_stack(ctx->tower_b);
	write(1, "sb\n", 3);
}

// ss: sa ve sb'yi ayni anda yap
void	execute_swap_both(t_context *ctx)
{
	swap_stack(ctx->tower_a);
	swap_stack(ctx->tower_b);
	write(1, "ss\n", 3);
}
