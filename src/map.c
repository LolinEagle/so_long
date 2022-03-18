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

char	*ft_get_next_line(int fd)
{
	char	*res;

	res = get_next_line(fd);
	// if (res[ft_strlen(res) - 1] == '\n')
	// 	res[ft_strlen(res) - 1] = '\0';
	return (res);
}

char	**ft_map(char *av, int *w, int *h)
{
	int		i;
	int		fd;
	char	**res;

	*h = ft_mapsize(av);
	res = malloc(sizeof(char *) * (*h + 1));
	fd = open(av, O_RDONLY);
	res[0] = ft_get_next_line(fd);
	*w = ft_strlen(res[0]);
	i = 0;
	while (res[i])
	{
		i++;
		res[i] = ft_get_next_line(fd);
	// 	if (ft_strlen(res[i]) != (size_t)*w)
	// 	{
	// 		while (i >= 0)
	// 		{
	// 			free(res[i]);
	// 			i--;
	// 		}
	// 		res = NULL;
	// 		break ;
	// 	}
	}
	close(fd);
	return (res);
}
