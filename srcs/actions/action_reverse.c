#include "pushswap.h"

// Yigini asagi dondur (son eleman basa gecer)
static void	reverse_rotate_stack(t_tower *tower)
{
	t_element	*last;
	t_element	*prev;

	if (tower->size < 2)
		return ;
	last = tower->top;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = tower->top;
	tower->top = last;
}

// rra: A yiginini asagi dondur (son eleman basa gecer)
void	execute_reverse_rotate_a(t_context *ctx)
{
	reverse_rotate_stack(ctx->tower_a);
	write(1, "rra\n", 4);
}

// rrb: B yiginini asagi dondur
void	execute_reverse_rotate_b(t_context *ctx)
{
	reverse_rotate_stack(ctx->tower_b);
	write(1, "rrb\n", 4);
}

// rrr: rra ve rrb'yi ayni anda yap
void	execute_reverse_rotate_both(t_context *ctx)
{
	reverse_rotate_stack(ctx->tower_a);
	reverse_rotate_stack(ctx->tower_b);
	write(1, "rrr\n", 4);
}
