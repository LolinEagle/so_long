/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:22:45 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/14 11:23:01 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		i;
	void	*mlx;
	void	*win;

	if (ac == 2)
	{
		mlx = mlx_init();
		if (!mlx)
			return (1);
		win = mlx_new_window(mlx, 1000, 1000, av[0] + 2);
		mlx_loop(mlx);
	}
	return (0);
}
