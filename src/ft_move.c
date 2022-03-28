/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:04:27 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/28 15:04:56 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(char *sc, t_mlx *mlx, int *i, void **img)
{
	ft_printf("%i\n", ++*i);
	if (*sc == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, img[0],
			TILE * mlx->pxy[X], TILE * mlx->pxy[Y]);
	else if (*sc == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, img[2],
			TILE * mlx->pxy[X], TILE * mlx->pxy[Y]);
		mlx->map[Y][X] = '0';
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, img[2],
			TILE * mlx->pxy[X], TILE * mlx->pxy[Y]);
}

void	ft_move_up(char *sc, t_mlx *mlx, int *i, void **img)
{
	ft_move(sc, mlx, i, img);
	*sc = mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]];
	if (mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] == 'C')
		mlx->pxy[C]--;
	else if (mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] == 'E' && mlx->pxy == 0)
		mlx_loop_end(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[1],
		TILE * (mlx->pxy[X]), TILE * (mlx->pxy[Y] - 1));
	mlx->pxy[Y]--;
}

void	ft_move_left(char *sc, t_mlx *mlx, int *i, void **img)
{
	ft_move(sc, mlx, i, img);
	*sc = mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1];
	if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] == 'C')
		mlx->pxy[C]--;
	else if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] == 'E' && mlx->pxy == 0)
		mlx_loop_end(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[1],
		TILE * (mlx->pxy[X] - 1), TILE * mlx->pxy[Y]);
	mlx->pxy[X]--;
}

void	ft_move_down(char *sc, t_mlx *mlx, int *i, void **img)
{
	ft_move(sc, mlx, i, img);
	*sc = mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]];
	if (mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] == 'C')
		mlx->pxy[C]--;
	else if (mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] == 'E' && mlx->pxy == 0)
		mlx_loop_end(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[1],
		TILE * mlx->pxy[X], TILE * (mlx->pxy[Y] + 1));
	mlx->pxy[Y]++;
}

void	ft_move_right(char *sc, t_mlx *mlx, int *i, void **img)
{
	ft_move(sc, mlx, i, img);
	*sc = mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1];
	if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] == 'C')
		mlx->pxy[C]--;
	else if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] == 'E' && mlx->pxy == 0)
		mlx_loop_end(mlx->mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img[1],
		TILE * (mlx->pxy[X] + 1), TILE * mlx->pxy[Y]);
	mlx->pxy[X]++;
}
