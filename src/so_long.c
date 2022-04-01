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

void	ft_moveplayer(t_mlx *mlx, char c)
{
	static int	i = 0;
	static char	sc = '0';
	int			res;

	res = 0;
	if (c == 'W' && mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] != '1')
		res = ft_move_up(&sc, mlx, &i);
	else if (c == 'A' && mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] != '1')
		res = ft_move_left(&sc, mlx, &i);
	else if (c == 'S' && mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] != '1')
		res = ft_move_down(&sc, mlx, &i);
	else if (c == 'D' && mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] != '1')
		res = ft_move_right(&sc, mlx, &i);
	if (res)
		mlx_loop_end(mlx->mlx);
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
	return (0);
}

int	ft_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

int	ft_sprite_animations(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	so_long(void *mlx, void *win, char **map)
{
	t_mlx	*so_long;

	so_long = ft_mlxnew(mlx, win, map);
	if (!so_long)
		return (ft_free(mlx, win, map));
	mlx_key_hook(win, ft_deal_key, so_long);
	mlx_hook(win, 17, 0, ft_close, mlx);
	mlx_loop_hook(mlx, ft_sprite_animations, so_long);
	mlx_loop(mlx);
	ft_mlx_destroy_image(so_long->mlx, so_long->img, 3);
	free(so_long->pxy);
	free(so_long);
	ft_free(mlx, win, map);
	return (0);
}
