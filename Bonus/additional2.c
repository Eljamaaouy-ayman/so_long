/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:22:08 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/23 13:24:28 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	powerr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = powerr(n);
	if (n == -2147483648)
		return (ft_strdup2("-2147483648"));
	if (n == 0)
		return (ft_strdup2("0"));
	s = (char *)malloc(i + 1);
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	i--;
	if (n < 0)
		n = n * (-1);
	while (i >= 0 && n > 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (i == 0)
		s[0] = '-';
	return (s);
}

void	move_player(t_game *game, int x_move, int y_move)
{
	int(x), (y);
	x = game->x + x_move;
	y = game->y + y_move;
	if (move(game, x, y) == 0)
		return ;
	game->map[game->x][game->y] = '0';
	game->y = y;
	game->x = x;
	game->map[x][y] = 'P';
	make_map(game);
}
int	pressed(int key_code, t_game *game)
{
	char		*str;
	static int	i;
	char		*str1;

	int x, y;
	x = game->x;
	y = game->y;
	(void)game;
	if (key_code == XK_Escape)
	{
		clean(game);
		exit(0);
	}
	else if (key_code == XK_w || key_code == XK_Up)
		move_player(game, -1, 0);
	else if (key_code == XK_s || key_code == XK_Down)
		move_player(game, 1, 0);
	else if (key_code == XK_a || key_code == XK_Left)
		move_player(game, 0, -1);
	else if (key_code == XK_d || key_code == XK_Right)
		move_player(game, 0, 1);
	if (x != game->x || y != game->y)
		i++;
	str1 = ft_itoa(i);
	str = ft_strjoin2("moves : ", str1);
	mlx_set_font(game->mlx, game->win, "9x15bold");
	mlx_string_put(game->mlx, game->win, 75, 15, 0x3e253c, str);
	return (free(str), free(str1), 1);
}