#include "pushswap.h"

// Yigindaki en kucuk indeksli elemani bul
static int	find_min_index(t_tower *tower)
{
	t_element	*curr;
	int			min;

	if (!tower || !tower->top)
		return (-1);
	curr = tower->top;
	min = curr->index;
	while (curr)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}

// Hedef indeksin yigindaki pozisyonunu bul (0: en ust)
static int	get_position(t_tower *tower, int target_index)
{
	t_element	*curr;
	int			pos;

	curr = tower->top;
	pos = 0;
	while (curr)
	{
		if (curr->index == target_index)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (-1);
}

// En kucuk elemani B yiginina tasi
// Eger eleman yiginin ust yarisindaysa rotate, alt yarisindaysa reverse rotate kullan
static void	push_min_to_b(t_context *ctx)
{
	int	min_idx;
	int	pos;
	int	size;

	min_idx = find_min_index(ctx->tower_a);
	pos = get_position(ctx->tower_a, min_idx);
	size = ctx->tower_a->size;
	if (pos <= size / 2)
	{
		while (ctx->tower_a->top->index != min_idx)
			execute_rotate_a(ctx);
	}
	else
	{
		while (ctx->tower_a->top->index != min_idx)
			execute_reverse_rotate_a(ctx);
	}
	execute_push_b(ctx);
}

// 5 elemanli siralama algoritmasi
// En kucuk iki elemani B'ye atar, kalan 3'luyu siralar, sonra B'dekileri geri alir
void	sort_small(t_context *ctx)
{
	if (!ctx || !ctx->tower_a)
		return ;
	// A'da 3 eleman kalana kadar en kucukleri B'ye at
	while (ctx->tower_a->size > 3)
		push_min_to_b(ctx);
	// Kalan 3 elemani sirala
	sort_tiny(ctx);
	// B'deki elemani geri A'ya al (zaten sirali gelecekler)
	while (ctx->tower_b->size > 0)
		execute_push_a(ctx);
}
