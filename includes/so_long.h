/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:59:36 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 21:16:14 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RES_Y 1080
# define RES_X 1920
# define ZOOM 300
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x0
# define GREY 0x999999
# define WHITE 0xFFFFFF
# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

enum
{
	ERR_ARGC = 1,
	ERR_ARGV,
	ERR_OPEN,
	ERR_READ,
	ERR_MAP_MALLOC,
	ERR_MAP_LINE_MALLOC,
	ERR_MAP,
	ERR_DRAWING,
	ERR_NAME,
	ERR_TXT_MALLOC,
	ERR_MLX_NEW_WIN,
	ERR_MLX_NEW_IMG,
	ERR_MLX_XPM_GEN,
	ERR_MALLOC
};

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_txt {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_txt;

typedef struct s_pt
{
	int	x;
	int	y;
}				t_pt;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct s_all_txts
{
	struct s_txt	*wl_txt;
	struct s_txt	*fl_txt;
	struct s_txt	*key_txt;
	struct s_txt	*kt_txt;
	struct s_txt	*dr_txt;
}				t_all_txts;

typedef struct s_config
{
	void		*mlx;
	void		*mlx_win;
	t_data		*img;
	int			*sizex;
	int			*sizey;
	int			zoom;
	t_pt		player;
	t_pt		left;
	t_pt		right;
	t_pt		up;
	t_pt		down;
	t_pt		size_map;
	t_pt		exit;
	int			collectibles;
	int			collected;
	int			open;
	char		**map;
	t_list		*lines;
	int			on_exit;
	t_all_txts	*txts;
	int			moves;
}				t_config;

// init.c
int		init_struct_config(t_config *c);
int		start_mlx(t_config *c);

// kill.c
int		terminator(t_config *c);
int		terminator2(t_config *c, int code);

// libft_utils.c
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// mlx_utils.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_pixel(t_txt *txt, int x, int y, t_config *c);

// parsing.c
int		last_check(t_config *c);
int		check_arg_name(char const *argv[], t_config *c);
int		parsing(int argc, const char *argv[], t_config *c);

// map.c
int		create_map(t_config *c);
int		add_line_in_lines(char *line, t_config *c);
void	show_list(t_config *c);
void	show_map(t_config *c);

// draw_map.c
int		map_drawer(t_config *c);

// hooks.c
int		key_hook(int keycode, t_config *c);
int		fonction_enregistee_pour_souris(int button, int x, int y, t_config *c);
int		cross_clicked(t_config *c);
int		nada(void *arg);

// moves.c
void	move(t_config *c, char keycode);

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
