/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:23:27 by ael-jama          #+#    #+#             */
/*   Updated: 2025/03/06 16:25:17 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr2(char **p, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(p[i++]);
	free(p);
}

void	clean_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (game->anim_coin[i])
			mlx_destroy_image(game->mlx, game->anim_coin[i]);
		i++;
	}
	free(game->anim_coin);
	i = 0;
	while (i < 6)
	{
		if (game->anim_player[i])
			mlx_destroy_image(game->mlx, game->anim_player[i]);
		i++;
	}
	free(game->anim_player);
}

void	clean(t_game *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	clean_animation(game);
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_arr2(game->map, game->rows);
	free(game->xycoin);
}

int	close_win(t_game *game)
{
	clean(game);
	exit(0);
	return (0);
}

void	put_img(t_game *game, void *some, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, some, j * 64, i * 64);
}
