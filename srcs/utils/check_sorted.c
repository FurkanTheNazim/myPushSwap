#include "pushswap.h"

// Yiginin sirali olup olmadigini kontrol et
int	is_stack_sorted(t_context *ctx)
{
	t_element	*current;

	if (!ctx || !ctx->tower_a || !ctx->tower_a->top)
		return (1);
	current = ctx->tower_a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
