/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:43:04 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 19:13:01 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	free_imgs_and_win(t_so_long *game)
{
	if (game->image.c)
		mlx_destroy_image(game->win.mlx_ptr, game->image.c);
	if (game->image.e)
		mlx_destroy_image(game->win.mlx_ptr, game->image.e);
	if (game->image.p)
		mlx_destroy_image(game->win.mlx_ptr, game->image.p);
	if (game->image.f)
		mlx_destroy_image(game->win.mlx_ptr, game->image.f);
	if (game->image.w)
		mlx_destroy_image(game->win.mlx_ptr, game->image.w);
	if (game->win.win_ptr)
		mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	if (game->win.mlx_ptr)
	{
		mlx_destroy_display(game->win.mlx_ptr);
		free(game->win.mlx_ptr);
	}
}

void	ft_exit_failure(t_so_long *game, char *str)
{
	int	i;

	if (game)
	{
		if (game->fd != -1)
			close (game->fd);
		if (game->map.matrix)
		{
			i = 0;
			while (game->map.matrix[i])
				free (game->map.matrix[i++]);
			free(game->map.matrix);
		}
		if (game->map.pos_c)
			free(game->map.pos_c);
		free_imgs_and_win(game);
		free(game);
	}
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_exit_success(t_so_long *game)
{
	int	i;

	if (game)
	{
		if (game->fd != -1)
			close (game->fd);
		if (game->map.matrix)
		{
			i = 0;
			while (game->map.matrix[i])
				free (game->map.matrix[i++]);
			free(game->map.matrix);
		}
		if (game->map.pos_c)
			free(game->map.pos_c);
		free_imgs_and_win(game);
		free(game);
	}
	exit(EXIT_SUCCESS);
}
