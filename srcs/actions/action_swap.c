#include "pushswap.h"

static void	swap_tower(t_tower *tower)
{
	t_element	*first;
	t_element	*second;

	if (!tower || !tower->top || !tower->top->next)
		return ;
	first = tower->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	tower->top = second;
}

void	execute_swap_a(t_context *ctx)
{
	swap_tower(ctx->tower_a);
	write(1, "sa\n", 3);
}

void	execute_swap_b(t_context *ctx)
{
	swap_tower(ctx->tower_b);
	write(1, "sb\n", 3);
}

void	execute_swap_both(t_context *ctx)
{
	swap_tower(ctx->tower_a);
	swap_tower(ctx->tower_b);
	write(1, "ss\n", 3);
}
