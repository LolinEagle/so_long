/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:23:16 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/14 11:23:20 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 128
# define ESC 65307
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
# define X 0
# define Y 1
# define C 2

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>// open

typedef struct s_axe
{
	int	x;
	int	y;
	int	z;
}		t_axe;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img[4];
	char	**map;
	int		*pxy;
}			t_mlx;

// ft_graphical.c	5 functions
void	ft_mlx_string_put(void *mlx, void *win, char *str);
int		ft_mlx_destroy_image(void *mlx, void **img, int i);
int		ft_mlx_new_image(void *mlx, void *win, char **map);

// ft_map_is_ok.c	5 functions
int		ft_map_is_ok(char **map, t_axe *wh);

// ft_map.c			5 functions
char	**ft_map(char *av, t_axe *wh);

// ft_move.c		5 functions
int		ft_move_up(char *sc, t_mlx *mlx, int *i);
int		ft_move_left(char *sc, t_mlx *mlx, int *i);
int		ft_move_down(char *sc, t_mlx *mlx, int *i);
int		ft_move_right(char *sc, t_mlx *mlx, int *i);

// so_long.c		5 functions
int		so_long(void *mlx, void *win, char **map);

// ft_init.c		4 functions
t_axe	*ft_axenew(void);
t_mlx	*ft_mlxnew(void *mlx, void *win, char **map);

// ft_main.c		2 functions
int		ft_free_mlx(void *mlx);
int		ft_free(void *mlx, void *win, char **map);

// main.c			5 functions

#endif
