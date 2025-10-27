#include "pushswap.h"

static void	rotate_tower(t_tower *tower)
{
	t_element	*first;
	t_element	*last;

	if (!tower || !tower->top || !tower->top->next)
		return ;
	first = tower->top;
	tower->top = first->next;
	last = tower->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	execute_rotate_a(t_context *ctx)
{
	rotate_tower(ctx->tower_a);
	write(1, "ra\n", 3);
}

void	execute_rotate_b(t_context *ctx)
{
	rotate_tower(ctx->tower_b);
	write(1, "rb\n", 3);
}

void	execute_rotate_both(t_context *ctx)
{
	rotate_tower(ctx->tower_a);
	rotate_tower(ctx->tower_b);
	write(1, "rr\n", 3);
}
