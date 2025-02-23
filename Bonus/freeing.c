/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:23:27 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/23 12:06:26 by ael-jama         ###   ########.fr       */
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
		mlx_destroy_image(game->mlx, game->anim_coin[i++]);
	}
	free(game->anim_coin);
	i = 0;
	while (game->anim_player[i])
	{
		mlx_destroy_image(game->mlx, game->anim_player[i++]);
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
