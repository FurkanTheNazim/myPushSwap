/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:47:01 by mahmmous          #+#    #+#             */
/*   Updated: 2025/10/25 19:47:03 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 0

typedef enum e_strategy
{
	STRAT_TINY,
	STRAT_SMALL,
	STRAT_RADIX
}	t_strategy;

#endif
