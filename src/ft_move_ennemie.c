/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ennemie.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:06:28 by frrusso           #+#    #+#             */
/*   Updated: 2022/04/05 17:06:30 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_ennemie_back(t_mlx *mlx, t_axe *xy, char *sc)
{
	mlx->map[xy->y][xy->x] = '0';
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[2],
		TILE * (xy->x), TILE * (xy->y));
	*sc = '0';
	xy->z = 4;
}

void	ft_move_ennemie_up(t_mlx *mlx, t_axe *xy, int *j, char *sc)
{
	if (mlx->pxy[X] == xy->x && mlx->pxy[Y] == xy->y - 1)
	{
		write(1, "Game Over\n", 10);
		mlx_loop_end(mlx->mlx);
	}
	else if (mlx->map[xy->y - 1][xy->x] == '0')
	{
		mlx->map[xy->y - 1][xy->x] = 'X';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
			TILE * (xy->x), TILE * (xy->y - 1));
		ft_move_ennemie_back(mlx, xy, sc);
	}
	else
	{
		xy->z++;
		*j += 1;
		ft_move_ennemie_bis(mlx, xy);
	}
}

void	ft_move_ennemie_down(t_mlx *mlx, t_axe *xy, int *j, char *sc)
{
	if (mlx->pxy[X] == xy->x && mlx->pxy[Y] == xy->y + 1)
	{
		write(1, "Game Over\n", 10);
		mlx_loop_end(mlx->mlx);
	}
	else if (mlx->map[xy->y + 1][xy->x] == '0')
	{
		mlx->map[xy->y + 1][xy->x] = 'X';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
			TILE * (xy->x), TILE * (xy->y + 1));
		ft_move_ennemie_back(mlx, xy, sc);
	}
	else
	{
		xy->z++;
		*j += 1;
		ft_move_ennemie_bis(mlx, xy);
	}
}

void	ft_move_ennemie_right(t_mlx *mlx, t_axe *xy, int *j, char *sc)
{
	if (mlx->pxy[X] == xy->x + 1 && mlx->pxy[Y] == xy->y)
	{
		write(1, "Game Over\n", 10);
		mlx_loop_end(mlx->mlx);
	}
	else if (mlx->map[xy->y][xy->x + 1] == '0')
	{
		mlx->map[xy->y][xy->x + 1] = 'X';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
			TILE * (xy->x + 1), TILE * (xy->y));
		ft_move_ennemie_back(mlx, xy, sc);
	}
	else
	{
		xy->z++;
		*j += 1;
		ft_move_ennemie_bis(mlx, xy);
	}
}

void	ft_move_ennemie_left(t_mlx *mlx, t_axe *xy, int *j, char *sc)
{
	if (mlx->pxy[X] == xy->x - 1 && mlx->pxy[Y] == xy->y)
	{
		write(1, "Game Over\n", 10);
		mlx_loop_end(mlx->mlx);
	}
	else if (mlx->map[xy->y][xy->x - 1] == '0')
	{
		mlx->map[xy->y][xy->x - 1] = 'X';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
			TILE * (xy->x - 1), TILE * (xy->y));
		ft_move_ennemie_back(mlx, xy, sc);
	}
	else
	{
		xy->z++;
		*j = 0;
		ft_move_ennemie_bis(mlx, xy);
	}
}
