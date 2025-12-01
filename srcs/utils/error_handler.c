#include "pushswap.h"

// Hata mesajini yazdir ve programdan cik
void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

// ft_split ile ayrilmis diziyi serbest birak
void	free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
