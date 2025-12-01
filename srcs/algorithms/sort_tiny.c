#include "pushswap.h"

// Yiginin sirali olup olmadigini kontrol et
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

// 3 elemanli siralama (Hardcoded logic)
// Tum olasiliklar (5 durum) icin en uygun islemleri yapar
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
		execute_swap_a(ctx); // 2 1 3 -> 1 2 3
	else if (a > b && b > c)
	{
		execute_swap_a(ctx);
		execute_reverse_rotate_a(ctx); // 3 2 1 -> 2 3 1 -> 1 2 3
	}
	else if (a > b && b < c && a > c)
		execute_rotate_a(ctx); // 3 1 2 -> 1 2 3
	else if (a < b && b > c && a < c)
	{
		execute_swap_a(ctx);
		execute_rotate_a(ctx); // 1 3 2 -> 3 1 2 -> 1 2 3
	}
	else if (a < b && b > c && a > c)
		execute_reverse_rotate_a(ctx); // 2 3 1 -> 1 2 3
}

// Kucuk veri setleri (2 veya 3 eleman) icin siralama
void	sort_tiny(t_context *ctx)
{
	if (!ctx || !ctx->tower_a)
		return ;
	if (ctx->total_count == 2)
	{
		// 2 eleman varsa ve sirali degilse sadece swap yap
		if (ctx->tower_a->top->index > ctx->tower_a->top->next->index)
			execute_swap_a(ctx);
	}
	else if (ctx->total_count == 3)
		sort_three(ctx);
}
