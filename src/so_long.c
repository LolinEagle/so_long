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

int	ft_deal_key(int key, void *mlx)
{
	if (key == ESC)
		mlx_loop_end(mlx);
	else
		ft_putchar_fd(key, 1);
	return (0);
}

void	so_long(void *mlx, void *win, char **map)
{
	mlx_key_hook(win, ft_deal_key, mlx);
	mlx_loop(mlx);
	ft_free(mlx, win, map);
}

// • Le but du joueur est de collecter tous les items
// présents sur la carte, puis de s’échapper en
// empruntant le chemin le plus court possible.
// • Les touches W, A, S, D doivent être utilisées
// afin de mouvoir le personnage principal.
// • Le joueur doit être capable de se déplacer dans
// 4 directions : haut, bas,gauche, droite.
// • Le joueur ne doit pas pouvoir se déplacer dans les murs.
// • À chaque mouvement, le compte total de mouvement
// doit être affiché dans le  shell.
// • Bien que les exemples donnés montrent un thème dauphin,
// vous êtes libre de créer l’univers que vous voulez.
// • Appuyer sur la touche ESC doit fermer la fenêtre
// et quitter le programme proprement.
// • Cliquer sur la croix en haut de la fenêtre doit fermer
// celle-ci et quitter le programme proprement.
