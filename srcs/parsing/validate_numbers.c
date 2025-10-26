#include "pushswap.h"

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

int	validate_integers(char **argv, int count)
{
	int i;
	long val;

	i = 0;
	while (i < count)
	{
		if (!is_number(argv[i]))
			return (0);
		val = ft_atoi(argv[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

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
