#include "pushswap.h"

// Sayinin kac bitlik oldugunu hesapla
// Bu bilgi Radix Sort icin gereklidir
int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}
