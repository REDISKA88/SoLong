#include "so_long.h"
void	ft_init(t_game *game)
{
	game->map_c = 0;
	game->map_e = 0;
	game->map_p = 0;
	game->width = 0;
	game->height = 0;
}

void	ft_check_kind(char *argv)
{
	int	j;

	j = ft_stlen(argv) - 1;
	if (argv[j] != 'r' && argv[j - 1] != 'e' && argv[j - 2] != 'b'
		&& argv[j - 3] != '.')
	{
		ft_errors(8);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_errors(1);
	ft_check_kind(argv[1]);
	ft_init(&game);
	ft_create_map2(&game, argv[1]);
	ft_start_game(&game);
	return (0);
}
