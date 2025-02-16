/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:55:41 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/15 16:33:17 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./getNexLine/get_next_line.h"
#include "./minilibx-linux/mlx.h"
#include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

typedef struct {
    int total_coin;
    int count_exit;
    int count_player;
    char **map;
    int rows;
    int colomns;
    int x;
    int y;
    int collectible;
    void *mlx;
    void *win;
} t_game;

int count_exit(t_game *game);
int	count_coins(t_game *game);
int	count_players(t_game *game);
int check_outlines(t_game *game);
int check_map(t_game *game, char *av);
size_t	ft_strlen2(const char *s);
int count_rows(t_game *game, char *av);
int	other_char(t_game *game);
int flood_fill(t_game *game);
int window(t_game *game);
