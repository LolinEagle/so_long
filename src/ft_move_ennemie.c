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

// void	ft_move_ennemie()
// {

// }

void	ft_move_ennemie_up(t_mlx *mlx, t_axe *xy, int *j)
{
	if (mlx->map[xy->y - 1][xy->x] == '0')
	{
		mlx->map[xy->y - 1][xy->x] = 'X';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
			TILE * (xy->x), TILE * (xy->y - 1));
		//ft_move_ennemie();
		//*sc = 
	}
	else if (mlx->pxy[X] == xy->x && mlx->pxy[Y] == xy->y - 1)
		mlx_loop_end(mlx->mlx);
	else
		*j += 1;
}

void	ft_move_ennemie_down(t_mlx *mlx, t_axe *xy, int *j)
{
	if (mlx->map[xy->y + 1][xy->x] == '0')
	{
		mlx->map[xy->y + 1][xy->x] = 'X';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[4],
			TILE * (xy->x), TILE * (xy->y + 1));
		//ft_move_ennemie();
		//*sc = 
	}
	else if (mlx->pxy[X] == xy->x && mlx->pxy[Y] == xy->y + 1)
		mlx_loop_end(mlx->mlx);
	else
		*j += 1;
}
