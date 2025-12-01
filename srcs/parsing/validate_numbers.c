#include "pushswap.h"

// String'in gecerli bir sayi olup olmadigini kontrol et
static int	is_number(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

// Sayilarin integer sinirlarinda olup olmadigini kontrol et
int	validate_integers(char **argv, int count)
{
	int		i;
	long	val;

	i = 0;
	while (i < count)
	{
		if (!is_number(argv[i]))
			return (0);
		val = ft_atol(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

// Tekrar eden sayi olup olmadigini kontrol et
int	check_duplicates(int *values, int count)
{
	int i;
	int j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
