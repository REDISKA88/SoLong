#include "so_long.h"
void	ft_errors(int code)
{
	if (code == 1)
	{
		write(1, "push map.ber into param\n", 24);
		exit(1);
	}
	if (code == 2)
	{
		write(1, "failed to open map", 18);
		write(1, "\n", 1);
		exit(1);
	}
	if (code == 3)
	{
		write(1, "NULL MAP", 8);
		write(1, "\n", 1);
		exit(1);
	}
	if (code == 4)
	{
		write(1, "valid map error", 15);
		write(1, "\n", 1);
		exit(1);
	}
	else
		ft_errors2(code);
}

void	ft_errors2(int code)
{
	if (code == 5)
	{
		write(1, "valid map error", 15);
		write(1, "\n", 1);
		exit(1);
	}
	if (code == 6)
	{
		write(1, "valid map fail", 14);
		write(1, "\n", 1);
		exit(1);
	}
	if (code == 7)
	{
		write(1, "load xpm fail", 14);
		write(1, "\n", 1);
		exit(1);
	}
	if (code == 8)
	{
		write(1, "invalid map format", 18);
		write(1, "\n", 1);
		exit(1);
	}
}
