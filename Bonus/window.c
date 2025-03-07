/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:23:02 by ael-jama          #+#    #+#             */
/*   Updated: 2025/03/06 16:24:16 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animation(t_game *game)
{
	static int	i;
	static int	j;
	static int	k;

	mlx_put_image_to_window(game->mlx, game->win, game->anim_player[i], game->y
		* 64, game->x * 64);
	usleep(100000);
	i++;
	if (i == 5)
		i = 0;
	while (k != (game->total_coin * 2))
	{
		if (game->xycoin[k] != -1 && game->xycoin[k + 1] != -1)
			mlx_put_image_to_window(game->mlx, game->win, game->anim_coin[j],
				game->xycoin[k], game->xycoin[k + 1]);
		k += 2;
	}
	k = 0;
	j++;
	if (j == 11)
		j = 0;
	return (0);
}

void	draw_map(t_game *game, int i, int j)
{
	static int	b;

	if (!game->mlx || !game->win || !game->floor || !game->enemy || !game->wall
		|| !game->anim_player || !game->exit)
		return (clean(game), exit(0));
	if (game->map[i][j] == '0')
		put_img(game, game->floor, i, j);
	else if (game->map[i][j] == 'N')
		put_img(game, game->enemy, i, j);
	else if (game->map[i][j] == '1')
		put_img(game, game->wall, i, j);
	else if (game->map[i][j] == 'P')
		put_img(game, game->anim_player[0], i, j);
	else if (game->map[i][j] == 'E')
		put_img(game, game->exit, i, j);
	else if (game->map[i][j] == 'C')
	{
		game->xycoin[b] = j * 64;
		game->xycoin[b + 1] = i * 64;
		b += 2;
	}
	if (b >= (game->total_coin * 2))
		b = 0;
}

void	make_map(t_game *game)
{
	int (i), (j);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_map(game, i, j);
			j++;
		}
		i++;
	}
}

void	norm(t_game *game, int i, int x, int y)
{
	while (i < game->total_coin * 2)
	{
		if (game->xycoin[i] == y * 64 && game->xycoin[i + 1] == x * 64)
		{
			game->xycoin[i] = -1;
			game->xycoin[i + 1] = -1;
		}
		i += 2;
	}
}

int	move(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->map[x][y] == '1')
		return (0);
	else if (game->map[x][y] == 'C')
	{
		game->collectible--;
		norm(game, i, x, y);
	}
	else if (game->map[x][y] == 'E')
	{
		if (game->collectible == 0)
			return (ft_printf("you win\n"), clean(game), exit(0), 1);
		else
			return (0);
	}
	else if (game->map[x][y] == 'N')
		return (clean(game), ft_printf("you lose\n"), exit(0), 1);
	return (1);
}
