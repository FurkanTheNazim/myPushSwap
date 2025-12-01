#include "pushswap.h"

// qsort icin karsilastirma fonksiyonu
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

// Degerleri normalize eden fonksiyon (0'dan N-1'e kadar siralar)
// Bu islem, algoritmanin sayilarin buyuklugunden bagimsiz calismasini saglar
void	normalize_values(int *values, int count, t_context *ctx)
{
	int	*i;
	int	j;
	int	*k;

	// Siralama icin gecici dizi
	k = malloc(sizeof(int) * count);
	if (!k)
		handle_error();
	// Indeksler icin dizi
	i = malloc(sizeof(int) * count);
	if (!i)
	{
		free(k);
		handle_error();
	}
	// Degerleri kopyala
	j = 0;
	while (j < count)
	{
		k[j] = values[j];
		j++;
	}
	// Gecici diziyi sirala
	qsort(k, count, sizeof(int), cmp_int);
	// Her degerin siralanmis dizideki indeksini bul
	j = 0;
	while (j < count)
	{
		int idx = 0;
		while (idx < count && k[idx] != values[j])
			idx++;
		i[j] = idx;
		j++;
	}
	// Orijinal degerleri indekslerle degistir
	j = 0;
	while (j < count)
	{
		values[j] = i[j];
		j++;
	}
	// Siralanmis diziyi context'e kaydet (referans icin)
	ctx->sorted_values = k;
	ctx->total_count = count;
	free(i);
}
