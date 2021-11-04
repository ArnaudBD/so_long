/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:01:10 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 19:01:13 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	draw_the_texture(t_config *c, int x, int y, t_txt *txt)
{
	int	i;
	int	j;
	int	pixel;

	j = 0;
	x *= c->zoom;
	y *= c->zoom;
	while (j < c->zoom)
	{
		i = 0;
		while (i < c->zoom)
		{
			pixel = get_pixel(txt, i, j, c);
			my_mlx_pixel_put(c->img, x + i, y + j, pixel);
			i++;
		}
		j++;
	}
	return (SUCCESS);
}

int	player_exit_placement(t_config *c, int x, int y)
{
	if (c->map[y][x] == 'P')
	{
		c->player.x = x;
		c->player.y = y;
	}
	if (c->map[y][x] == 'E')
	{
		c->exit.x = x;
		c->exit.y = y;
	}
	x++;
	return (x);
}

int	map_drawer(t_config *c)
{
	int	x;
	int	y;

	y = 0;
	while (y <= c->size_map.y)
	{
		x = 0;
		while (x <= c->size_map.x)
		{
			if (c->map[y][x] == '1')
				draw_the_texture(c, x, y, c->txts->wl_txt);
			if (c->map[y][x] == '0')
				draw_the_texture(c, x, y, c->txts->fl_txt);
			if (c->map[y][x] == 'P')
				draw_the_texture(c, x, y, c->txts->kt_txt);
			if (c->map[y][x] == 'E')
				draw_the_texture(c, x, y, c->txts->dr_txt);
			if (c->map[y][x] == 'C')
				draw_the_texture(c, x, y, c->txts->key_txt);
			x = player_exit_placement(c, x, y);
		}
		y++;
	}
	mlx_put_image_to_window(c->mlx, c->mlx_win, c->img->img, 0, 0);
	return (SUCCESS);
}
