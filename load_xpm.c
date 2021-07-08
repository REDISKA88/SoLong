#include "so_long.h"
void	ft_create_xpm_p(t_xpm_p *player, t_game *game)
{
	player->img = mlx_xpm_file_to_image(game->mlx, "./xpm/player.xpm",
			&player->width, &player->height);
	if (!player->img)
	{
		perror("fail load xpm");
		exit(1);
	}
}

void	ft_create_xpm_g(t_xpm_g *grass, t_game *game)
{
	grass->img = mlx_xpm_file_to_image(game->mlx, "./xpm/grass.xpm",
			&grass->width, &grass->height);
	if (!grass->img)
	{
		perror("fail load xpm");
		exit(1);
	}
}

void	ft_create_xpm_w(t_xpm_w *wall, t_game *game)
{
	wall->img = mlx_xpm_file_to_image(game->mlx, "./xpm/wall.xpm", &wall->width,
			&wall->height);
	if (!wall->img)
	{
		perror("fail load xpm");
		exit(1);
	}
}

void	ft_create_xpm_c(t_xpm_c *coin, t_game *game)
{
	coin->img = mlx_xpm_file_to_image(game->mlx, "./xpm/coin.xpm", &coin->width,
			&coin->height);
	if (!coin->img)
	{
		perror("fail load xpm");
		exit(1);
	}
}

void	ft_create_xpm_e(t_xpm_e *exits, t_game *game)
{
	exits->img = mlx_xpm_file_to_image(game->mlx, "./xpm/exit.xpm",
			   &exits->width, &exits->height);
	if (!exits->img)
	{
		perror("fail load xpm");
		exit(1);
	}
}
