/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:04:40 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/23 10:41:30 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_to_ptr(t_game *game)
{
	int (w), (h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player1.xpm", &w,
			&h);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin3.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit1.xpm", &w, &h);
	if (!game->floor || !game->wall || !game->player || !game->coin
		|| !game->exit)
		return (clean(game), 0);
	return (1);
}

void	clean(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_arr(game->map, game->rows);
}

int	close_win(t_game *game)
{
	clean(game);
	exit(0);
	return (0);
}
