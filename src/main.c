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

int	ft_mapsize(char *file)
{
	int		i;
	int		fd;
	char	*gnl;

	i = 1;
	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		i++;
	}
	close(fd);
	free(gnl);
	return (i);
}

char	**ft_map(char *av)
{
	int		i;
	int		fd;
	char	*file;
	char	**res;

	i = 0;
	file = ft_strjoin("../maps/", av);
	res = malloc(sizeof(char *) * ft_mapsize(file));
	fd = open(file, O_RDONLY);
	res[i] = get_next_line(fd);
	while (res[i])
	{
		i++;
		res[i] = get_next_line(fd);
	}
	close(fd);
	free(file);
	return (res);
}

int	main(int ac, char **av)
{
	char	**map;
	void	*mlx;
	void	*win;

	if (ac > 1)
	{
		mlx = mlx_init();
		if (!mlx)
			return (1);
		map = ft_map(av[1]);
		win = mlx_new_window(mlx, 1000, 1000, av[0] + 2);
		if (!win)
			return (1);
		mlx_loop(mlx);
	}
	return (0);
}
