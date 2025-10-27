#include "pushswap.h"

static void	execute_sort(t_context *ctx)
{
	t_strategy	strat;

	strat = select_strategy(ctx->total_count);
	if (strat == STRAT_TINY)
		sort_tiny(ctx);
	else if (strat == STRAT_SMALL)
		sort_small(ctx);
}

int	main(int argc, char **argv)
{
	int	*values;
	int	count;
	t_context *ctx;

	values = NULL;
	count = parse_arguments(argc, argv, &values);
	if (count == 0)
		return (0);
	if (!validate_integers((argc == 2) ? ft_split(argv[1], ' ') : argv + 1, count))
	{
		handle_error();
	}
	if (check_duplicates(values, count))
	{
		handle_error();
	}
	ctx = initialize_context(values, count);
	execute_sort(ctx);
	cleanup_context(ctx);
	free(values);
	return (0);
}
