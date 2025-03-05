/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:04:40 by ael-jama          #+#    #+#             */
/*   Updated: 2025/03/05 23:05:46 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loading_player_animation(int w, int h, t_game *game)
{
	game->anim_player = malloc(sizeof(void *) * 6);
	game->anim_player[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/player1.xpm", &w, &h);
	game->anim_player[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/player2.xpm", &w, &h);
	game->anim_player[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player3.xpm", &w, &h);
	game->anim_player[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/player4.xpm", &w, &h);
	game->anim_player[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/player5.xpm", &w, &h);
	game->anim_player[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/player6.xpm", &w, &h);
}

void	loading_coin_animation(int w, int h, t_game *game)
{
	game->anim_coin = malloc(sizeof(void *) * 12);
	game->anim_coin[0] = mlx_xpm_file_to_image(game->mlx, "textures/coin1.xpm",
			&w, &h);
	game->anim_coin[1] = mlx_xpm_file_to_image(game->mlx, "textures/coin2.xpm",
			&w, &h);
	game->anim_coin[2] = mlx_xpm_file_to_image(game->mlx, "textures/coin3.xpm",
			&w, &h);
	game->anim_coin[3] = mlx_xpm_file_to_image(game->mlx, "textures/coin4.xpm",
			&w, &h);
	game->anim_coin[4] = mlx_xpm_file_to_image(game->mlx, "textures/coin5.xpm",
			&w, &h);
	game->anim_coin[5] = mlx_xpm_file_to_image(game->mlx, "textures/coin6.xpm",
			&w, &h);
	game->anim_coin[6] = mlx_xpm_file_to_image(game->mlx, "textures/coin7.xpm",
			&w, &h);
	game->anim_coin[7] = mlx_xpm_file_to_image(game->mlx, "textures/coin8.xpm",
			&w, &h);
	game->anim_coin[8] = mlx_xpm_file_to_image(game->mlx, "textures/coin9.xpm",
			&w, &h);
	game->anim_coin[9] = mlx_xpm_file_to_image(game->mlx, "textures/coin10.xpm",
			&w, &h);
	game->anim_coin[10] = mlx_xpm_file_to_image(game->mlx,
			"textures/coin11.xpm", &w, &h);
	game->anim_coin[11] = mlx_xpm_file_to_image(game->mlx,
			"textures/coin12.xpm", &w, &h);
}

int	img_to_ptr(t_game *game)
{
	int (w), (h);
	w = 64;
	h = 64;
	game->enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm", &w,
			&h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
	game->coin = mlx_xpm_file_to_image(game->mlx, "textures/coin3.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit1.xpm", &w, &h);
	loading_player_animation(w, h, game);
	loading_coin_animation(w, h, game);
	if (!game->floor || !game->wall || !game->coin || !game->enemy
		|| !game->exit)
		return (clean(game), 0);
	return (1);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = -1;
	k = ft_strlen2(s1);
	j = ft_strlen2(s2);
	s3 = malloc(k + j + 1);
	if (s3 == NULL)
		return (NULL);
	while (++i < k)
		s3[i] = s1[i];
	i--;
	while (i++ < k + j - 1)
		s3[i] = s2[i - k];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strdup2(const char *s1)
{
	size_t	s_len;
	size_t	i;
	char	*s2;

	s_len = ft_strlen2(s1);
	s2 = (char *)malloc(s_len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
