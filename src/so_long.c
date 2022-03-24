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

int	ft_deal_key(int key, t_mlx *so_long)
{
	if (key == ESC)
		mlx_loop_end(so_long->mlx);
	else if (key == UP || key == W)
		ft_putchar_fd('W', 1);
	else if (key == LEFT || key == A)
		ft_putchar_fd('A', 1);
	else if (key == DOWN || key == S)
		ft_putchar_fd('S', 1);
	else if (key == RIGHT || key == D)
		ft_putchar_fd('D', 1);
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
	mlx_key_hook(win, ft_deal_key, so_long);
	mlx_hook(win, 17, 0, ft_close, mlx);
	mlx_loop(mlx);
	free(so_long);
	ft_free(mlx, win, map);
	return (0);
}

// • Le but du joueur est de collecter tous les items
// présents sur la carte, puis de s’échapper en
// empruntant le chemin le plus court possible.

// • Les touches W, A, S, D doivent être utilisées
// afin de mouvoir le personnage principal.

// • Le joueur ne doit pas pouvoir se déplacer dans les murs.

// • À chaque mouvement, le compte total de mouvement
// doit être affiché dans le  shell.
