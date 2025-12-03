/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tower_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:19:32 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:20:23 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_tower	*create_tower(char name)
{
	t_tower	*tower;

	tower = malloc(sizeof(t_tower));
	if (!tower)
		handle_error();
	tower->top = NULL;
	tower->size = 0;
	tower->name = name;
	return (tower);
}

void	destroy_tower(t_tower *tower)
{
	t_element	*tmp;
	t_element	*next;

	if (!tower)
		return ;
	tmp = tower->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(tower);
}

t_element	*create_element(int value, int index)
{
	t_element	*el;

	el = malloc(sizeof(t_element));
	if (!el)
		handle_error();
	el->value = value;
	el->index = index;
	el->next = NULL;
	return (el);
}
