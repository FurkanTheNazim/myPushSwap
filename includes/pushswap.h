/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:46:52 by mahmmous          #+#    #+#             */
/*   Updated: 2025/10/26 17:09:49 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "definitions.h"

typedef struct s_element
{
	int					value;
	int					index;
	struct s_element	*next;
}	t_element;

typedef struct s_tower
{
	t_element	*top;
	int			size;
	char		name;
}	t_tower;

typedef struct s_context
{
	t_tower	*tower_a;
	t_tower	*tower_b;
	int		*sorted_values;
	int		total_count;
}	t_context;

void	execute_swap_a(t_context *ctx);
void	execute_swap_b(t_context *ctx);
void	execute_swap_both(t_context *ctx);
void	execute_push_a(t_context *ctx);
void	execute_push_b(t_context *ctx);
void	execute_rotate_a(t_context *ctx);
void	execute_rotate_b(t_context *ctx);
void	execute_rotate_both(t_context *ctx);
void	execute_reverse_rotate_a(t_context *ctx);
void	execute_reverse_rotate_b(t_context *ctx);
void	execute_reverse_rotate_both(t_context *ctx);

t_tower		*create_tower(char name);
void		destroy_tower(t_tower *tower);
void		add_element_top(t_tower *tower, t_element *elem);
t_element	*remove_element_top(t_tower *tower);
t_element	*create_element(int value, int index);

int			parse_arguments(int argc, char **argv, int **values);
int			validate_integers(char **argv, int count);
int			check_duplicates(int *values, int count);
void		normalize_values(int *values, int count, t_context *ctx);

t_context	*initialize_context(int *values, int count);
void		cleanup_context(t_context *ctx);
t_strategy	select_strategy(int count);

void		sort_tiny(t_context *ctx);
void		sort_small(t_context *ctx);
void		sort_radix(t_context *ctx);

void		handle_error(void);
void		free_split(char **split);

#endif
