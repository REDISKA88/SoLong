#include "so_long.h"
void ft_start_game(t_map *mp, t_game *game)
{
	t_xpm xp;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, mp->height * 32,
							   mp->width * 32, "SO LONG");
	ft_create_xpm(&xp, game);
	//ft_create_hooks()

}
