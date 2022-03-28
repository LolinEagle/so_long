/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:23:07 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/14 11:23:11 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*ft_findplayer(char **map)
{
	int	i;
	int	j;
	int	*res;

	res = malloc(sizeof(int) * 2);
	if (!res)
		return (NULL);
	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				res[2]++;
			if (map[i][j] == 'P')
			{
				res[1] = i;
				res[0] = j;
			}
		}
	}
	return (res);
}

void	ft_moveplayer(t_mlx *mlx, char c)
{
	static int	i = 0;
	static char	sc = '0';
	void		*img[3];
	int			nul;

	img[0] = mlx_xpm_file_to_image(mlx->mlx, "assets/sExit.xpm", &nul, &nul);
	img[1] = mlx_xpm_file_to_image(mlx->mlx, "assets/sPlayer.xpm", &nul, &nul);
	img[2] = mlx_xpm_file_to_image(mlx->mlx, "assets/sTile.xpm", &nul, &nul);
	if (c == 'W' && mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] != '1')
		ft_move_up(&sc, mlx, &i, img);
	else if (c == 'A' && mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] != '1')
		ft_move_left(&sc, mlx, &i, img);
	else if (c == 'S' && mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] != '1')
		ft_move_down(&sc, mlx, &i, img);
	else if (c == 'D' && mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] != '1')
		ft_move_right(&sc, mlx, &i, img);
}

int	ft_deal_key(int key, t_mlx *mlx)
{
	if (key == ESC)
		mlx_loop_end(mlx->mlx);
	else if (key == UP || key == W)
		ft_moveplayer(mlx, 'W');
	else if (key == LEFT || key == A)
		ft_moveplayer(mlx, 'A');
	else if (key == DOWN || key == S)
		ft_moveplayer(mlx, 'S');
	else if (key == RIGHT || key == D)
		ft_moveplayer(mlx, 'D');
	if (0)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	ft_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	so_long(void *mlx, void *win, char **map)
{
	t_mlx	*so_long;

	so_long = malloc(sizeof(t_mlx));
	if (!so_long)
		return (ft_free(mlx, win, map));
	so_long->mlx = mlx;
	so_long->win = win;
	so_long->map = map;
	so_long->pxy = ft_findplayer(map);
	mlx_key_hook(win, ft_deal_key, so_long);
	mlx_hook(win, 17, 0, ft_close, mlx);
	mlx_loop(mlx);
	free(so_long);
	ft_free(mlx, win, map);
	return (0);
}
