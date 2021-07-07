#include "so_long.h"
void	ft_create_xpm(t_xpm *xp, t_game *game)
{
	xp->player.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",xp->player
	.width, xp->player.height);

	xp->grass.img = mlx_xpm_file_to_image(game->mlx, "grass.xpm",xp->grass
			.width, xp->grass.height);
	xp->coin.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",xp->coin
			.width, xp->coin.height);
	xp->exit.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",xp->exit
			.width, xp->exit.height);
	xp->wall.img = mlx_xpm_file_to_image(game->mlx, "player.xpm",xp->wall
			.width, xp->wall.height);
}
