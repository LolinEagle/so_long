/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:46:13 by frrusso           #+#    #+#             */
/*   Updated: 2022/04/05 14:46:41 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_key(void **img, int i)
{
	if (i == 0)
		return (img[5]);
	else if (i == 1)
		return (img[6]);
	else if (i == 2)
		return (img[7]);
	else
		return (img[6]);
}

void	ft_next_frame_key(t_mlx *mlx)
{
	static int	i = 0;
	int			x;
	int			y;

	i++;
	if (i > 3)
		i = 0;
	y = 0;
	while (mlx->map[++y])
	{
		x = 0;
		while (mlx->map[y][++x] && mlx->map[y][x] != '\n')
		{
			if (mlx->map[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					ft_key(mlx->img, i), TILE * x, TILE * y);
			}
		}
	}
}

void	ft_move_ennemie(t_mlx *mlx)
{
	static int	i = 0;
	static int	j = 0;
	// static char	sc = '0';
	t_axe		*xy;

	i++;
	xy = ft_axenew();
	while (mlx->map[xy->y++] && i % 2 == 0)
	{
		while (mlx->map[xy->y][xy->x++] && mlx->map[xy->y][xy->x] != '\n')
		{
			if (mlx->map[xy->y][xy->x] == 'X')
			{
				if (j == 0)
					ft_move_ennemie_up(mlx, xy, &j);
				else if (j == 1)
					j++;
				else if (j == 2)
					ft_move_ennemie_down(mlx, xy, &j);
				else if (j == 3)
					j++;
			}
		}
	}
	free(xy);
}
