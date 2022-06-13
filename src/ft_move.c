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

void	ft_move(char *sc, t_mlx *mlx, int *i)
{
	char	*str;

	ft_printf("\r%i", ++*i);
	str = ft_itoa(*i);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[3], 0, 0);
	ft_mlx_string_put(mlx->mlx, mlx->win, str);
	free(str);
	if (*sc == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[0],
			TILE * mlx->pxy[X], TILE * mlx->pxy[Y]);
	else if (*sc == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[2],
			TILE * mlx->pxy[X], TILE * mlx->pxy[Y]);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[2],
			TILE * mlx->pxy[X], TILE * mlx->pxy[Y]);
}

int	ft_move_up(char *sc, t_mlx *mlx, int *i)
{
	ft_move(sc, mlx, i);
	*sc = mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]];
	if (mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] == 'C')
	{
		mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] = '0';
		mlx->pxy[C]--;
	}
	else if (mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] == 'X')
		return (write(1, "Game Over\n", 10));
	else if (mlx->map[mlx->pxy[Y] - 1][mlx->pxy[X]] == 'E' && mlx->pxy[2] == 0)
		return (write(1, "Congratulations\n", 16));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1],
		TILE * (mlx->pxy[X]), TILE * (mlx->pxy[Y] - 1));
	mlx->pxy[Y]--;
	ft_move_ennemie(mlx);
	return (0);
}

int	ft_move_left(char *sc, t_mlx *mlx, int *i)
{
	ft_move(sc, mlx, i);
	*sc = mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1];
	if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] == 'C')
	{
		mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] = '0';
		mlx->pxy[C]--;
	}
	else if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] == 'X')
		return (write(1, "Game Over\n", 10));
	else if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] - 1] == 'E' && mlx->pxy[2] == 0)
		return (write(1, "Congratulations\n", 16));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1],
		TILE * (mlx->pxy[X] - 1), TILE * mlx->pxy[Y]);
	mlx->pxy[X]--;
	ft_move_ennemie(mlx);
	return (0);
}

int	ft_move_down(char *sc, t_mlx *mlx, int *i)
{
	ft_move(sc, mlx, i);
	*sc = mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]];
	if (mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] == 'C')
	{
		mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] = '0';
		mlx->pxy[C]--;
	}
	else if (mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] == 'X')
		return (write(1, "Game Over\n", 10));
	else if (mlx->map[mlx->pxy[Y] + 1][mlx->pxy[X]] == 'E' && mlx->pxy[2] == 0)
		return (write(1, "Congratulations\n", 16));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1],
		TILE * mlx->pxy[X], TILE * (mlx->pxy[Y] + 1));
	mlx->pxy[Y]++;
	ft_move_ennemie(mlx);
	return (0);
}

int	ft_move_right(char *sc, t_mlx *mlx, int *i)
{
	ft_move(sc, mlx, i);
	*sc = mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1];
	if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] == 'C')
	{
		mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] = '0';
		mlx->pxy[C]--;
	}
	else if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] == 'X')
		return (write(1, "Game Over\n", 10));
	else if (mlx->map[mlx->pxy[Y]][mlx->pxy[X] + 1] == 'E' && mlx->pxy[2] == 0)
		return (write(1, "Congratulations\n", 16));
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img[1],
		TILE * (mlx->pxy[X] + 1), TILE * mlx->pxy[Y]);
	mlx->pxy[X]++;
	ft_move_ennemie(mlx);
	return (0);
}
