#include "pushswap.h"

t_strategy	select_strategy(int count)
{
	if (count <= 3)
		return (STRAT_TINY);
	if (count <= 5)
		return (STRAT_SMALL);
	return (STRAT_RADIX);
}
