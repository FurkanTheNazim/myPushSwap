#include "pushswap.h"

// Siralama islemini baslatan fonksiyon
static void	execute_sort(t_context *ctx)
{
	t_strategy	strat;

	// Eleman sayisina gore strateji sec
	strat = select_strategy(ctx->total_count);
	if (strat == STRAT_TINY)
		sort_tiny(ctx); // 3 eleman icin
	else if (strat == STRAT_SMALL)
		sort_small(ctx); // 5 eleman icin
	else if (strat == STRAT_RADIX)
		sort_radix(ctx); // Diger durumlar icin Radix sort
}

int	main(int argc, char **argv)
{
	int	*values;
	int	count;
	t_context *ctx;

	values = NULL;
	// Argumanlari ayikla ve sayiya cevir
	count = parse_arguments(argc, argv, &values);
	if (count == 0)
		return (0); // Hic arguman yoksa cik
	// Sayilarin gecerliligini kontrol et (sayi mi, int sinirlarinda mi)

	// Tekrar eden sayi var mi kontrol et
	if (check_duplicates(values, count))
	{
		handle_error();
	}
	// Program baglamini ve yiginlari hazirla
	ctx = initialize_context(values, count);
	// Siralamayi baslat
	if (!is_stack_sorted(ctx))
		execute_sort(ctx);
	// Temizlik yap ve cik
	cleanup_context(ctx);
	free(values);
	return (0);
}
