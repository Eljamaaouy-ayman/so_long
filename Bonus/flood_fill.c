/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:58:18 by eljamaaouya       #+#    #+#             */
/*   Updated: 2025/03/06 17:31:14 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **p, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		free(p[i++]);
	free(p);
}

int	check(char **map, t_game *game)
{
	int (i), (j);
	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->colomns)
		{
			if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	to_fill(t_game *game, char **map, int y, int x)
{
	if (y >= game->rows || x >= game->colomns || y < 0 || x < 0)
		return ;
	if (map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != '0'
		&& map[y][x] != 'E' && map[y][x] != 'N')
		return ;
	if (map[y][x] == 'C')
		game->collectible++;
	if ((game->map[y][x] == 'E') && (game->collectible != game->total_coin))
	{
		map[y][x] = 'V';
		return ;
	}
	map[y][x] = 'V';
	to_fill(game, map, y + 1, x);
	to_fill(game, map, y - 1, x);
	to_fill(game, map, y, x + 1);
	to_fill(game, map, y, x - 1);
}

int	flood_fill(t_game *game)
{
	char	**map;

	int (i), (j);
	map = malloc(sizeof(char *) * (game->rows + 1));
	i = -1;
	while (++i < game->rows)
	{
		j = -1;
		map[i] = malloc(sizeof(char) * (game->colomns + 1));
		while (++j < game->colomns)
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
	if (check(map, game) == 0)
		return (free_arr(map, game->rows), 0);
	return (free_arr(map, game->rows), 1);
}

int	check_name(char *name)
{
	int	len;

	len = ft_strlen2(name) - 1;
	while (len >= 0)
	{
		if (name[len] == '/' && name[len + 1] == '.')
			return (0);
		len--;
	}
	len = ft_strlen2(name);
	if (len > 4 && name[len - 1] == 'r' && name[len - 2] == 'e'
		&& name[len - 3] == 'b' && name[len - 4] == '.' && name[0] != '.')
		return (1);
	return (0);
}
