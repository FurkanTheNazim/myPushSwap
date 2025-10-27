#include "pushswap.h"

static void	reverse_rotate_tower(t_tower *tower)
{
	t_element	*prev;
	t_element	*last;

	if (!tower || !tower->top || !tower->top->next)
		return ;
	prev = NULL;
	last = tower->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = tower->top;
	tower->top = last;
}

void	execute_reverse_rotate_a(t_context *ctx)
{
	reverse_rotate_tower(ctx->tower_a);
	write(1, "rra\n", 4);
}

void	execute_reverse_rotate_b(t_context *ctx)
{
	reverse_rotate_tower(ctx->tower_b);
	write(1, "rrb\n", 4);
}

void	execute_reverse_rotate_both(t_context *ctx)
{
	reverse_rotate_tower(ctx->tower_a);
	reverse_rotate_tower(ctx->tower_b);
	write(1, "rrr\n", 4);
}
