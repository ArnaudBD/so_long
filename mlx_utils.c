/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:50:30 by abiju-du          #+#    #+#             */
/*   Updated: 2021/11/04 20:18:05 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr
		+ (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_txt *txt, int x, int y, t_config *c)
{
	int	*addr_int;
	int	ratio_x;
	int	ratio_y;

	addr_int = (int *)txt->addr;
	ratio_x = txt->width / c->zoom;
	ratio_y = txt->height / c->zoom;
	addr_int += y * ratio_y * txt->line_length / (txt->bits_per_pixel / 8)
		+ x * ratio_x;
	return (*addr_int);
}

int	start_textures(t_config *c)
{
	static char		*t[16] = {"img/wall.xpm", "img/floor.xpm",
			"img/key.xpm", "img/door.xpm", "img/knight.xpm"};
	struct s_txt	**p[5];
	int				i;

	p[0] = &c->txts->wl_txt;
	p[1] = &c->txts->fl_txt;
	p[2] = &c->txts->key_txt;
	p[3] = &c->txts->dr_txt;
	p[4] = &c->txts->kt_txt;
	i = 0;
	while (i < 5)
	{
		(*p[i])->img = mlx_xpm_file_to_image(c->mlx, t[i],
				&((*p[i])->width), &((*p[i])->height));
		if ((*p[i])->img == NULL)
			return (terminator2(c, ERR_MLX_XPM_GEN));
		(*p[i])->addr = mlx_get_data_addr((*p[i])->img,
				&(*p[i])->bits_per_pixel, &(*p[i])->line_length,
				&c->txts->wl_txt->endian);
		i++;
	}
	return (SUCCESS);
}

int	start_mlx(t_config *c)
{
	c->mlx = mlx_init();
	if (c->mlx == NULL)
		return (FAILURE);
	mlx_get_screen_size(c->mlx, c->sizex, c->sizey);
	while (*c->sizex < ((c->size_map.x + 1) * c->zoom)
		|| *c->sizey < ((c->size_map.y + 2) * c->zoom))
		c->zoom--;
	c->mlx_win = mlx_new_window(c->mlx, (c->size_map.x + 1) * c->zoom,
			(c->size_map.y + 1) * c->zoom, "so_long");
	if (c->mlx_win == NULL)
		return (terminator2(c, ERR_MLX_NEW_WIN));
	c->img->img = mlx_new_image(c->mlx, (c->size_map.x + 1) * c->zoom,
			(c->size_map.y + 1) * c->zoom);
	if (c->img->img == NULL)
	{
		return (terminator2(c, ERR_MLX_NEW_IMG));
	}
	c->img->addr = mlx_get_data_addr(c->img->img,
			&c->img->bits_per_pixel, &c->img->line_length, &c->img->endian);
	if (start_textures(c) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
