/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:58:07 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 19:53:53 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TILE
#  define TILE 50
# endif

# include "../Libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysymdef.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_points {
	int	x;
	int	y;
}	t_points;

typedef struct s_map {
	char		**matrix;
	int			height;
	int			width;
	int			num_p;
	int			num_c;
	int			num_e;
	t_points	pos_p;
	t_points	pos_e;
	t_points	*pos_c;
}	t_map;

typedef struct s_win {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_win;

typedef struct t_image {
	void	*p;
	void	*c;
	void	*e;
	void	*w;
	void	*f;
}	t_image;

typedef struct s_so_long {
	int		fd;
	int		moves;
	int		collected;
	t_map	map;
	t_win	win;
	t_image	image;
}	t_so_long;

t_so_long	*init_game(void);
void		check_map(t_so_long *game);
void		put_images(t_so_long *game);
void		make_window(t_so_long *game);
void		do_flood_fill(t_so_long *game);
void		ft_exit_success(t_so_long *game);
void		collect_and_print(t_so_long *game);
void		save_map(t_so_long *game, char *file);
int			handle_key(int keycode, t_so_long *game);
void		ft_exit_failure(t_so_long *game, char *str);

#endif
