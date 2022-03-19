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

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	**ft_map(char *av, int *w, int *h)
{
	int		i;
	int		fd;
	char	**res;

	*h = ft_mapsize(av);
	res = malloc(sizeof(char *) * (*h + 1));
	fd = open(av, O_RDONLY);
	res[0] = get_next_line(fd);
	*w = ft_strlen_gnl(res[0]);
	i = 0;
	while (res[i])
	{
		i++;
		res[i] = get_next_line(fd);
		if (ft_strlen_gnl(res[i]) != (size_t)*w)
		{
			while (i >= 0)
			{
				free(res[i]);
				i--;
			}
			res = NULL;
			break ;
		}
	}
	close(fd);
	return (res);
}
