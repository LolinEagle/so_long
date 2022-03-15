/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:48:32 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/15 16:48:39 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapsize(char *file)
{
	int		i;
	int		fd;
	char	*gnl;

	i = 0;
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

char	**ft_map(char *av, int *x, int *y)
{
	int		i;
	int		fd;
	char	*file;
	char	**res;

	i = 0;
	file = ft_strjoin("../maps/", av);
	*y = ft_mapsize(file);
	res = malloc(sizeof(char *) * (*y + 1));
	fd = open(file, O_RDONLY);
	res[i] = get_next_line(fd);
	*x = ft_strlen(res[i]);
	while (res[i])
	{
		i++;
		res[i] = get_next_line(fd);
	}
	close(fd);
	free(file);
	return (res);
}
