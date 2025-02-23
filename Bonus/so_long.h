/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-jama <ael-jama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:55:41 by ael-jama          #+#    #+#             */
/*   Updated: 2025/02/23 11:35:35 by ael-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./../minilibx-linux/mlx.h"
# include "./getNexLine/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>

typedef struct s_game
{
	int		total_coin;
	int		count_exit;
	int		count_player;
	char	**map;
	int		rows;
	int		colomns;
	int		x;
	int		y;
	int		collectible;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*coin;
	void	*enemy;
	void	**anim_player;
	void	**anim_coin;
	int		*xycoin;
}			t_game;

int			count_exit(t_game *game);
int			count_coins(t_game *game);
int			count_players(t_game *game);
int			check_outlines(t_game *game);
int			check_map(t_game *game, char *av);
size_t		ft_strlen2(const char *s);
int			count_rows(t_game *game, char *av);
int			other_char(t_game *game);
int			flood_fill(t_game *game);
int			window(t_game *game);
int			img_to_ptr(t_game *game);
void		move_player(t_game *game, int x_move, int y_move);
int			check_name(char *name);
int			pressed(int key_code, t_game *game);
void		make_map(t_game *game);
void		draw_map(t_game *game, int i, int j);
int			animation(t_game *game);
int			close_win(t_game *game);
char		*ft_strjoin2(char const *s1, char const *s2);
char		*ft_itoa(int n);
void		free_arr2(char **p, int rows);
void		clean(t_game *game);
void		free_arr(char **p, int rows);
int	close_win(t_game *game);
void	clean_animation(t_game *game);
char	*ft_strdup2(const char *s1);
int	move(t_game *game, int x, int y);

#endif