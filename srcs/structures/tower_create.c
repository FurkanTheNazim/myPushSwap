#include "pushswap.h"

// Yeni bir yigin (tower) olustur
t_tower	*create_tower(char name)
{
	t_tower *tower;

	tower = malloc(sizeof(t_tower));
	if (!tower)
		handle_error();
	tower->top = NULL;
	tower->size = 0;
	tower->name = name;
	return (tower);
}

// Yigini ve icindeki tum elemanlari temizle
void	destroy_tower(t_tower *tower)
{
	t_element *tmp;
	t_element *next;

	if (!tower)
		return;
	tmp = tower->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(tower);
}

// Yeni bir eleman olustur
t_element	*create_element(int value, int index)
{
	t_element *el;

	el = malloc(sizeof(t_element));
	if (!el)
		handle_error();
	el->value = value;
	el->index = index;
	el->next = NULL;
	return (el);
}
