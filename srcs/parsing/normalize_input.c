#include "pushswap.h"

static int	cmp_int(const void *a, const void *b)
{
	int ia = *(const int *)a;
	int ib = *(const int *)b;
	if (ia < ib)
		return (-1);
	if (ia > ib)
		return (1);
	return (0);
}

void	normalize_values(int *values, int count, t_context *ctx)
{
	int	*i;
	int	j;
	int	*k;

	k = malloc(sizeof(int) * count);
	if (!k)
		handle_error();
	i = malloc(sizeof(int) * count);
	if (!i)
	{
		free(k);
		handle_error();
	}
	j = 0;
	while (j < count)
	{
		k[j] = values[j];
		j++;
	}
	qsort(k, count, sizeof(int), cmp_int);
	j = 0;
	while (j < count)
	{
		int idx = 0;
		while (idx < count && k[idx] != values[j])
			idx++;
		i[j] = idx;
		j++;
	}
	j = 0;
	while (j < count)
	{
		values[j] = i[j];
		j++;
	}
	ctx->sorted_values = k;
	ctx->total_count = count;
	free(i);
}
