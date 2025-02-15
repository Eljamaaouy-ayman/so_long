/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eljamaaouyayman <eljamaaouyayman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:28:57 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/11 17:13:01 by eljamaaouya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_players(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'P')
				game->count_player++;
			i++;
		}
		j++;
	}
	return (game->count_player);
}

int	count_coins(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'C')
				game->total_coin++;
			i++;
		}
		j++;
	}
	return (game->total_coin);
}

int	count_exit(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			if (game->map[j][i] == 'E')
				game->count_exit++;
			i++;
		}
		j++;
	}
	return (game->count_exit);
}

int	other_char(t_game *game)
{
	int (i), (j);
	j = 0;
	while (game->map[j] != NULL)
	{
		i = 0;
		while (game->map[j][i] != '\n' && game->map[j][i] != '\0')
		{
			if (game->map[j][i] != 'E' && game->map[j][i] != 'P' && game->map[j][i] != 'C'
				&& game->map[j][i] != '1' && game->map[j][i] != '0')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

size_t	ft_strlen2(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}