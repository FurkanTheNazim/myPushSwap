#include "pushswap.h"

// Eleman sayisina gore siralama stratejisini secen fonksiyon
t_strategy	select_strategy(int count)
{
	if (count <= 3)
		return (STRAT_TINY); // 3 veya daha az eleman
	if (count <= 5)
		return (STRAT_SMALL); // 5 veya daha az eleman
	return (STRAT_RADIX); // Diger durumlar (buyuk veri setleri)
}
