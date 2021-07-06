#include "so_long.h"
void	ft_mp_init(t_map *mp)
{
	mp->map_c = 0;
	mp->map_e = 0;
	mp->map_p = 0;
	mp->width = 0;
	mp->height = 0;
}

int	main(int argc, char **argv)
{
	t_map 	mp;
	t_game game;

	int		map_fd;

	if (argc != 2)
		ft_errors(1);
	ft_mp_init(&mp);

	ft_create_map2(&mp,argv[1]);
	ft_start_game(&mp, &game);
	return (0);
}
