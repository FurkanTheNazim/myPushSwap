#include "pushswap.h"

// Yiginindaki ilk iki elemani takas et
static void	swap_tower(t_tower *tower)
{
	t_element	*first;
	t_element	*second;

	if (!tower || !tower->top || !tower->top->next)
		return ;
	first = tower->top;
	second = first->next;
	// Baglantilari guncelle
	first->next = second->next;
	second->next = first;
	tower->top = second;
}

// sa: A yiginindaki ilk iki elemani takas et
void	execute_swap_a(t_context *ctx)
{
	swap_tower(ctx->tower_a);
	write(1, "sa\n", 3);
}

// sb: B yiginindaki ilk iki elemani takas et
void	execute_swap_b(t_context *ctx)
{
	swap_tower(ctx->tower_b);
	write(1, "sb\n", 3);
}

// ss: sa ve sb'yi ayni anda yap
void	execute_swap_both(t_context *ctx)
{
	swap_tower(ctx->tower_a);
	swap_tower(ctx->tower_b);
	write(1, "ss\n", 3);
}
