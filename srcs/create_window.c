/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:17:00 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 19:04:40 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	put_background(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'F')
				mlx_put_image_to_window(game->win.mlx_ptr,
					game->win.win_ptr, game->image.f, j * TILE, i * TILE);
			if (game->map.matrix[i][j] == '1')
				mlx_put_image_to_window(game->win.mlx_ptr,
					game->win.win_ptr, game->image.w, j * TILE, i * TILE);
			j++;
		}
		i++;
	}
}

static void	put_foreground(t_so_long *game)
{
	int	i;

	i = 0;
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
		game->image.e, game->map.pos_e.y * TILE, game->map.pos_e.x * TILE);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
		game->image.p, game->map.pos_p.y * TILE, game->map.pos_p.x * TILE);
	while (i < game->map.num_c)
	{
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
			game->image.c, game->map.pos_c[i].y * TILE,
			game->map.pos_c[i].x * TILE);
		i++;
	}
}

static void	create_images(t_so_long *game)
{
	int	width;
	int	height;

	width = TILE;
	height = TILE;
	game->image.c = mlx_xpm_file_to_image(game->win.mlx_ptr,
			"imgs/collectable.xpm", &width, &height);
	game->image.e = mlx_xpm_file_to_image(game->win.mlx_ptr,
			"imgs/exit.xpm", &width, &height);
	game->image.p = mlx_xpm_file_to_image(game->win.mlx_ptr,
			"imgs/player.xpm", &width, &height);
	game->image.f = mlx_xpm_file_to_image(game->win.mlx_ptr,
			"imgs/floor.xpm", &width, &height);
	game->image.w = mlx_xpm_file_to_image(game->win.mlx_ptr,
			"imgs/wall.xpm", &width, &height);
	if (game->image.c == NULL || game->image.p == NULL || game->image.e == NULL
		|| game->image.f == NULL || game->image.w == NULL)
		ft_exit_failure(game, "Failure transforming files to images");
}

void	put_images(t_so_long *game)
{
	put_background(game);
	put_foreground(game);
}

void	make_window(t_so_long *game)
{
	game->win.mlx_ptr = mlx_init();
	if (game->win.mlx_ptr == NULL)
		ft_exit_failure(game, "Failed to set up connection with mlx_init()");
	game->win.win_ptr = mlx_new_window(game->win.mlx_ptr,
			game->map.width * TILE, game->map.height * TILE, "So long");
	if (game->win.win_ptr == NULL)
		ft_exit_failure(game, "Failed to create window");
	create_images(game);
	put_images(game);
}
