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

# define TRUE 1 // Dogru durumu temsil eder
# define FALSE 0 // Yanlis durumu temsil eder
# define ERROR -1 // Hata durumunu temsil eder
# define SUCCESS 0 // Basarili islem durumunu temsil eder


typedef enum e_strategy
{
	STRAT_TINY, // Cok kucuk veri setleri icin siralama stratejisi (3 eleman)
	STRAT_SMALL, // Kucuk veri setleri icin siralama stratejisi (5 eleman)
	STRAT_RADIX // Buyuk veri setleri icin Radix sort stratejisi
}	t_strategy;

#endif
