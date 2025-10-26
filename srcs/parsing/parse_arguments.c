#include "pushswap.h"

int	parse_arguments(int argc, char **argv, int **values)
{
	char	**parts;
	int	count;
	int	i;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		parts = ft_split(argv[1], ' ');
		if (!parts)
			handle_error();
		i = 0;
		while (parts[i])
			i++;
		count = i;
		*values = malloc(sizeof(int) * count);
		if (!*values)
		{
			free_split(parts);
			handle_error();
		}
		i = 0;
		while (parts[i])
		{
			(*values)[i] = ft_atoi(parts[i]);
			i++;
		}
		free_split(parts);
		return (count);
	}
	count = argc - 1;
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
