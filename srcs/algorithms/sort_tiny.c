#include "pushswap.h"

static int	is_sorted(t_tower *tower)
{
	t_element	*curr;

	if (!tower || !tower->top)
		return (1);
	curr = tower->top;
	while (curr->next)
	{
		if (curr->index > curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}

static void	sort_three(t_context *ctx)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(ctx->tower_a))
		return ;
	a = ctx->tower_a->top->index;
	b = ctx->tower_a->top->next->index;
	c = ctx->tower_a->top->next->next->index;
	if (a > b && b < c && a < c)
		execute_swap_a(ctx);
	else if (a > b && b > c)
	{
		execute_swap_a(ctx);
		execute_reverse_rotate_a(ctx);
	}
	else if (a > b && b < c && a > c)
		execute_rotate_a(ctx);
	else if (a < b && b > c && a < c)
	{
		execute_swap_a(ctx);
		execute_rotate_a(ctx);
	}
	else if (a < b && b > c && a > c)
		execute_reverse_rotate_a(ctx);
}

void	sort_tiny(t_context *ctx)
{
	if (!ctx || !ctx->tower_a)
		return ;
	if (ctx->total_count == 2)
	{
		if (ctx->tower_a->top->index > ctx->tower_a->top->next->index)
			execute_swap_a(ctx);
	}
	else if (ctx->total_count == 3)
		sort_three(ctx);
}
