#include "so_long.h"
void	check_size(t_game *game)
{
	int	i;

	i = 0;
	game->width = ft_stlen(game->map[i]);
	i++;
	while (i < game->height)
	{
		if (ft_stlen(game->map[i]) != game->width)
		{
			write(1, "invalid size map", 16);
			write(1, "\n", 1);
			exit(1);
		}
		i++;
	}
}

void	ft_check_epc(t_game *game)
{
	if (game->map_p != 1)
	{
		write(1, "player must be one", 18);
		write(1, "\n", 1);
		exit(1);
	}
	if (game->map_e < 1)
	{
		write(1, "Portal error", 12);
		write(1, "\n", 1);
		exit(1);
	}
	if (game->map_c < 1)
	{
		write(1, "coins error", 11);
		write(1, "\n", 1);
		exit(1);
	}
}

void	ft_border_checker(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] == '1' &&
		game->map[i][ft_stlen(game->map[i]) - 1] == '1')
			i++;
		else
			ft_errors(4);
	}
}

void	ft_check_up_down(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			ft_errors(5);
		i++;
	}
	i = 0;
	while (game->map[game->height - 1][i])
	{
		if (game->map[game->height - 1][i] != '1')
			ft_errors(5);
		i++;
	}
	ft_border_checker(game);
	check_size(game);
	ft_check_epc(game);
}
