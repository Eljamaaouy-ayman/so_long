/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljamaaouyayman <eljamaaouyayman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:58:18 by eljamaaouya       #+#    #+#             */
/*   Updated: 2025/02/14 15:30:31 by eljamaaouya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_arr(char **arr, int rows)
{
	while(rows > 0)
	{
		rows--;
		free(arr[rows]);
	}
	free(arr);
}

int check(char **map)
{
	int (i), (j);

	i = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while(map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C')
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

void to_fill(t_game *game,char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->rows || y >= game->colomns ||
		game->map[x][y] == '1')
		return ;
	if (game->map[x][y] == 'C')
		game->collectible++;
	if (game->map[x][y] == 'E' && (game->collectible != game->total_coin))
	{
		game->map[x][y] = 'V';
		return ;
	}
	game->map[x][y] = 'V';
	to_fill(game, map, x + 1, y);
	to_fill(game, map, x - 1, y);
	to_fill(game, map, x, y + 1);
	to_fill(game, map, x, y - 1);
}

int flood_fill(t_game *game)
{
	char **map;

	int (i), (j);
	map = malloc(sizeof(char *) * game->rows);
	i = -1;
	while(++i < game->rows)
	{
		j = -1;
		map[i] = malloc(sizeof(char) * game->colomns);
		while(++j < game->colomns)
		{
			map[i][j] = game->map[i][j];
			if (game->map[i][j] == 'P')
			{
				game->x = i;
				game->y = j;
			}
		}
		game->map[i][j] = '\0';
	}
	map[i] = NULL;
	to_fill(game, map, game->x, game->y);
	if (check(map) == 0)
		return (free_arr(map, game->rows), 0);
	return (free_arr(map, game->rows), 1);
}

int check_name(char *name)
{
	int len;

	len = ft_strlen2(name);
	if (len > 4 && name[len - 1] == 'r' && name[len - 2] == 'e'
		&& name[len - 3] == 'b' && name[len - 4] == '.')
		return (1);
	return (0);
}
