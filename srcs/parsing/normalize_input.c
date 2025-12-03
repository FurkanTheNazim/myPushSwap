/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:21:18 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:21:36 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_int_array(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	*allocate_temp_arrays(int count, int **indices)
{
	int	*temp;

	temp = malloc(sizeof(int) * count);
	if (!temp)
		handle_error();
	*indices = malloc(sizeof(int) * count);
	if (!*indices)
	{
		free(temp);
		handle_error();
	}
	return (temp);
}

static void	map_indices(int *values, int *temp, int *indices, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
	{
		j = -1;
		while (++j < count)
		{
			if (values[i] == temp[j])
			{
				indices[i] = j;
				break ;
			}
		}
	}
}

void	normalize_values(int *values, int count, t_context *ctx)
{
	int	*temp;
	int	*indices;
	int	i;

	temp = allocate_temp_arrays(count, &indices);
	i = -1;
	while (++i < count)
		temp[i] = values[i];
	sort_int_array(temp, count);
	map_indices(values, temp, indices, count);
	i = -1;
	while (++i < count)
		values[i] = indices[i];
	ctx->sorted_values = temp;
	ctx->total_count = count;
	free(indices);
}
