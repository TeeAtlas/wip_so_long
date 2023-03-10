/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:22:14 by taboterm          #+#    #+#             */
/*   Updated: 2023/03/11 22:20:33 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// exit (0) = EXIT_SUCCESS
// exit (1) = EXIT_FAILURE
//initializing game and establishing window size
void	initialize_game(t_game *game)
{
	game->mlx = mlx_init();
	game->tile_dimension = TILE;
	read_map(game);
	elements_init(game);
	min_max_elements(game);
	walled_sides(game);
	walled_topbottom(game);
	xpm_to_pixel(game);
	game->win = mlx_new_window(game->mlx, game->map.w * TILE, \
								game->map.h * TILE, "so_long");
	load_image(game);
	find_player(game);
}

void	arg_check(int argc)
{
	if (argc != 2)
	{
		ft_printf("System Failure: Too few arguements!\n", argc);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{	
	t_game		*game;

	arg_check(argc);
	game = NULL;
	game = (t_game *) malloc (sizeof(t_game));
	game->map.map_file = argv[1];
	if (filecheck(game) == 0)
	{
		free(game);
		return (EXIT_FAILURE);
	}
	initialize_game(game);
	if (is_valid_path(game) == 0)
	{
		free(game);
		return (EXIT_FAILURE);
	}
	mlx_hook(game->win, 17, 0, destroy, game);
	mlx_key_hook(game->win, player_moves, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
