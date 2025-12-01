#include "pushswap.h"

// Komut satiri argumanlarini ayiklayan fonksiyon
static int	parse_single_arg(char *arg, int **values)
{
	char	**parts;
	int		count;
	int		i;

	parts = ft_split(arg, ' ');
	if (!parts)
		handle_error();
	i = 0;
	while (parts[i])
		i++;
	count = i;
	if (!validate_integers(parts, count))
	{
		free_split(parts);
		handle_error();
	}
	*values = malloc(sizeof(int) * count);
	if (!*values)
	{
		free_split(parts);
		handle_error();
	}
	i = -1;
	while (++i < count)
		(*values)[i] = ft_atoi(parts[i]);
	free_split(parts);
	return (count);
}

// Komut satiri argumanlarini ayiklayan fonksiyon
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
