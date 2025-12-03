/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:24:01 by mahmmous          #+#    #+#             */
/*   Updated: 2025/12/03 19:24:18 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_strategy	select_strategy(int count)
{
	if (count <= 3)
		return (STRAT_TINY);
	if (count <= 5)
		return (STRAT_SMALL);
	return (STRAT_RADIX);
}
