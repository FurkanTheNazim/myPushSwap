/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:21:46 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:21:47 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_parts(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
		i++;
	return (i);
}

static int	*allocate_and_fill(char **parts, int count)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * count);
	if (!values)
	{
		free_split(parts);
		handle_error();
	}
	i = -1;
	while (++i < count)
		values[i] = ft_atoi(parts[i]);
	return (values);
}

static int	parse_single_arg(char *arg, int **values)
{
	char	**parts;
	int		count;

	parts = ft_split(arg, ' ');
	if (!parts)
		handle_error();
	count = count_parts(parts);
	if (count == 0)
	{
		free_split(parts);
		handle_error();
	}
	if (!validate_integers(parts, count))
	{
		free_split(parts);
		handle_error();
	}
	*values = allocate_and_fill(parts, count);
	free_split(parts);
	return (count);
}

int	parse_arguments(int argc, char **argv, int **values)
{
	int	count;
	int	i;

	if (argc < 2)
		return (0);
	if (argc == 2)
		return (parse_single_arg(argv[1], values));
	count = argc - 1;
	if (!validate_integers(argv + 1, count))
		handle_error();
	*values = malloc(sizeof(int) * count);
	if (!*values)
		handle_error();
	i = 0;
	while (i < count)
	{
		(*values)[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (count);
}
