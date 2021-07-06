#ifndef SO_LONG_H
#define SO_LONG_H
#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
}				t_game;

typedef struct s_hooks
{
	int map_e;
	int map_p;
	int map_c;
	int width;
	int height;
	char	**map;
}				t_hooks;

typedef struct s_xpm
{
	int map_e;
	int map_p;
	int map_c;
	int width;
	int height;
	char	**map;
}				t_xpm;

typedef struct s_map
{
	int map_e;
	int map_p;
	int map_c;
	int width;
	int height;
	char	**map;
}				t_map;

void	ft_errors(int code);
int	ft_maplines(char *argv1, t_map *mp);
void	ft_mp_init(t_map *mp);
void ft_create_map2(t_map *mp, char *argv);
void ft_check_symb(t_map *mp, char *mapi);
void	ft_count_epc(char map, t_map *mp);
void	ft_check_epc(t_map *mp);
void	ft_border_checker(t_map *mp);
void ft_start_game(t_map *mp, t_game *game);






void	check_size(t_map *mp);


char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar(char c);
void	ft_free_array(char **temp);
int	ft_strlen(const char *s);
int	str_char(const char *s, char c);
char	*ft_substr(char const *str, unsigned int start, int len);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dst, const void *src, int num);
int	ft_strncmp(const char *s1, const char *s2, size_t num);
void ft_check_up_bord(t_map *mp);
#endif
