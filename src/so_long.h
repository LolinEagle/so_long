/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:23:16 by frrusso           #+#    #+#             */
/*   Updated: 2022/03/14 11:23:20 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE 128

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>// open
# include <stdio.h>// perror
# include <string.h>// strerror

typedef struct s_axe
{
	int	x;
	int	y;
	int	z;
}		t_axe;

// ft_map_is_ok.c	4 functions
int		ft_map_is_ok(char **map, t_axe *wh);

// map.c			4 functions
char	**ft_map(char *av, t_axe *wh);

// graphical.c		2 functions
void	ft_mlx_new_image(void *mlx, void *win, char **map);

// so_long.c		2 functions
void	so_long(void *mlx, void *win);

// main.c			4 functions
t_axe	*ft_axenew(void);

#endif
