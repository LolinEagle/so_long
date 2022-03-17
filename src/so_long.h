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

// map.c		2 functions
char	**ft_map(char *av, int *w, int *h);

// so_long.c	1 functions
void	so_long(void);

// main.c		3 functions

#endif
