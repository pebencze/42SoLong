/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:52:38 by pbencze           #+#    #+#             */
/*   Updated: 2024/03/05 18:59:49 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

t_so_long	*init_game(void)
{
	t_so_long	*game;

	game = (t_so_long *)ft_calloc(sizeof(t_so_long), 1);
	if (!game)
		ft_exit_failure(NULL, "Failure on memory allocation for game-struct");
	return (game);
}

int	main(int ac, char **av)
{
	t_so_long	*game;
	char		*extension;
	int			result;

	if (ac == 2)
	{
		game = init_game();
		extension = ft_substr(av[1], (ft_strlen(av[1]) - 4), 5);
		result = ft_strcmp(extension, ".ber");
		free(extension);
		if (result)
			ft_exit_failure(game, "Invalid map format. Usage: *.ber");
		save_map(game, av[1]);
		check_map(game);
		make_window(game);
		mlx_key_hook(game->win.win_ptr, &handle_key, game);
		mlx_hook(game->win.win_ptr, 17, 1L << 0,
			(int (*)()) & ft_exit_success, game);
		mlx_loop(game->win.mlx_ptr);
	}
	else
		ft_printf("Usage: map file");
	return (0);
}
