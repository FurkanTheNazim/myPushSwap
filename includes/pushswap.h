/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmmous <mahmmous@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:46:52 by mahmmous          #+#    #+#             */
/*   Updated: 2025/10/28 00:22:57 by mahmmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"
# include "definitions.h"

// Bagli liste eleman yapisi
typedef struct s_element
{
	int					value; // Elemanin degeri
	int					index; // Siralama icin normalize edilmis indeks degeri
	struct s_element	*next; // Bir sonraki elemana isaretci
}	t_element;

// Yigin (Stack) yapisi
typedef struct s_tower
{
	t_element	*top; // Yiginin en ustundeki eleman
	int			size; // Yigindaki eleman sayisi
	char		name; // Yiginin adi ('a' veya 'b')
}	t_tower;

// Ana program baglam yapisi (Context)
typedef struct s_context
{
	t_tower	*tower_a; // A yigini
	t_tower	*tower_b; // B yigini
	int		*sorted_values; // Siralanmis degerler dizisi (referans icin)
	int		total_count; // Toplam eleman sayisi
}		t_context;

// Hareket (Action) fonksiyonlari
void		execute_swap_a(t_context *ctx); // sa: A yiginindaki ilk iki elemani takas et
void		execute_swap_b(t_context *ctx); // sb: B yiginindaki ilk iki elemani takas et
void		execute_swap_both(t_context *ctx); // ss: sa ve sb'yi ayni anda yap
void		execute_push_a(t_context *ctx); // pa: B'den A'ya eleman it
void		execute_push_b(t_context *ctx); // pb: A'dan B'ye eleman it
void		execute_rotate_a(t_context *ctx); // ra: A yiginini yukari dondur (ilk eleman sona gecer)
void		execute_rotate_b(t_context *ctx); // rb: B yiginini yukari dondur
void		execute_rotate_both(t_context *ctx); // rr: ra ve rb'yi ayni anda yap
void		execute_reverse_rotate_a(t_context *ctx); // rra: A yiginini asagi dondur (son eleman basa gecer)
void		execute_reverse_rotate_b(t_context *ctx); // rrb: B yiginini asagi dondur
void		execute_reverse_rotate_both(t_context *ctx); // rrr: rra ve rrb'yi ayni anda yap

// Yigin yonetim fonksiyonlari
t_tower		*create_tower(char name); // Yeni bir yigin olustur
void		destroy_tower(t_tower *tower); // Yigini ve icindeki elemanlari temizle
void		add_element_top(t_tower *tower, t_element *elem); // Yigina eleman ekle
t_element	*remove_element_top(t_tower *tower); // Yigindan eleman cikar
t_element	*create_element(int value, int index); // Yeni bir eleman olustur

// Arguman isleme ve dogrulama fonksiyonlari
int			parse_arguments(int argc, char **argv, int **values); // Komut satiri argumanlarini ayikla
int			validate_integers(char **argv, int count); // Sayi formatini kontrol et
int			check_duplicates(int *values, int count); // Tekrar eden sayi var mi kontrol et
void		normalize_values(int *values, int count, t_context *ctx); // Degerleri 0'dan baslayarak indeksle
int			is_stack_sorted(t_context *ctx); // Yiginin sirali olup olmadigini kontrol et

// Baslatma ve temizleme
t_context	*initialize_context(int *values, int count); // Program baglamini baslat
void		cleanup_context(t_context *ctx); // Program baglamini temizle
t_strategy	select_strategy(int count); // Siralama stratejisini sec

// Siralama algoritmalari
void		sort_tiny(t_context *ctx); // 3 elemanli siralama
void		sort_small(t_context *ctx); // 5 elemanli siralama
void		sort_radix(t_context *ctx); // Radix sort (buyuk veriler icin)

int			get_max_bits(int max_num);

void		handle_error(void);
void		free_split(char **split);

#endif
