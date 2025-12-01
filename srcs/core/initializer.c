#include "pushswap.h"

// Program baglamini ve yiginlari baslatan fonksiyon
t_context	*initialize_context(int *values, int count)
{
	t_context *ctx;
	int	*i;
	int	j;

	// Context icin bellek ayir
	ctx = malloc(sizeof(t_context));
	if (!ctx)
		handle_error();
	// Gecici dizi icin bellek ayir
	i = malloc(sizeof(int) * count);
	if (!i)
	{
		free(ctx);
		handle_error();
	}
	// Degerleri kopyala
	j = 0;
	while (j < count)
	{
		i[j] = values[j];
		j++;
	}
	// Degerleri normalize et (0'dan baslayarak sirala)
	normalize_values(values, count, ctx);
	// A ve B yiginlarini olustur
	ctx->tower_a = create_tower('a');
	ctx->tower_b = create_tower('b');
	// Elemanlari A yiginina tersten ekle (cunku stack LIFO mantigiyla calisir)
	j = count - 1;
	while (j >= 0)
	{
		t_element *el = create_element(i[j], values[j]);
		add_element_top(ctx->tower_a, el);
		j--;
	}
	ctx->total_count = count;
	free(i);
	return (ctx);
}
