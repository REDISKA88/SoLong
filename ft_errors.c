#include "so_long.h"
void	ft_errors(int code)
{
	if (code == 1)
	{
		write(1, "push map.ber into param", 23);
		exit(1);
	}
	if (code == 2)
	{
		write(1, "failed to open map", 18);
		exit(1);
	}
	if (code == 3)
	{
		write(1, "NULL MAP", 8);
		exit(1);
	}
	if (code == 4)
	{
		write(1, "border error width", 18);
		exit(1);
	}
	else
		ft_errors2(code);
}

void	ft_errors2(int code)
{
	if (code == 5)
	{
		write(1, "border up/down error", 20);
		exit(1);
	}
	if (code == 6)
	{
		write(1, "valid map fail", 14);
		exit(1);
	}
	if (code == 7)
	{
		write(1, "load xpm fail", 14);
		exit(1);
	}
}
