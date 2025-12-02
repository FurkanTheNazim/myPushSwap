#include "pushswap.h"

// Yigini yukari dondur (ilk eleman sona gecer)
static void	rotate_stack(t_tower *tower)
{
	t_element	*first;
	t_element	*last;

	if (tower->size < 2)
		return ;
	first = remove_element_top(tower);
	last = tower->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	tower->size++;
}

// ra: A yiginini yukari dondur
void	execute_rotate_a(t_context *ctx)
{
	rotate_stack(ctx->tower_a);
	write(1, "ra\n", 3);
}

// rb: B yiginini yukari dondur
void	execute_rotate_b(t_context *ctx)
{
	rotate_stack(ctx->tower_b);
	write(1, "rb\n", 3);
}

// rr: ra ve rb'yi ayni anda yap
void	execute_rotate_both(t_context *ctx)
{
	rotate_stack(ctx->tower_a);
	rotate_stack(ctx->tower_b);
	write(1, "rr\n", 3);
}
