# include "includes/so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr +
    (y * data->line_length +
     x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     get_pixel(t_txt *txt, int x, int y)
{
    int         *addr_int;  
    int             ratio_x;
    int             ratio_y;

    addr_int = (int*)txt->addr;
    ratio_x = txt->width / ZOOM;
    ratio_y = txt->height / ZOOM;
    addr_int += y * ratio_y * txt->line_length / (txt->bits_per_pixel / 8) + x * ratio_x;
    return *addr_int;
}

int    start_mlx(t_config *c)
{
    c->mlx = mlx_init();
    if (c->mlx == NULL)
        return (FAILURE);
    mlx_get_screen_size(c->mlx, c->sizex, c->sizey);
printf("sizex == %d\nsizey == %d\nzoom == %d\nsize map x == %d\nsize map y == %d\n", *c->sizex, *c->sizey, c->zoom, c->size_map.x, c->size_map.y);
    while (*c->sizex < ((c->size_map.x + 1) * c->zoom) || *c->sizey < ((c->size_map.y + 1) * c->zoom))
    {
        c->zoom /= 2;
    }
    
    c->mlx_win = mlx_new_window(c->mlx, (c->size_map.x + 1)* ZOOM, (c->size_map.y + 1) * ZOOM, "so_long");
 //  c->mlx_win = NULL;
    if (c->mlx_win == NULL)
        return (terminator2(c, ERR_MLX_NEW_WIN));
    c->img->img = mlx_new_image(c->mlx, (c->size_map.x + 1)* ZOOM, (c->size_map.y + 1) * ZOOM);
    if (c->img->img == NULL)
    {
        return (terminator2(c, ERR_MLX_NEW_IMG));
    }
	c->img->addr = mlx_get_data_addr(c->img->img, &c->img->bits_per_pixel, &c->img->line_length, &c->img->endian);
    c->txts->wl_txt->img = mlx_xpm_file_to_image(c->mlx, "img/wall.xpm", &c->txts->wl_txt->width, &c->txts->wl_txt->height);
    if (c->txts->wl_txt->img == NULL)
    {
        return (terminator2(c, ERR_MLX_XPM_GEN));
    }
	c->txts->wl_txt->addr = mlx_get_data_addr(c->txts->wl_txt->img, &c->txts->wl_txt->bits_per_pixel, &c->txts->wl_txt->line_length,
                        			&c->txts->wl_txt->endian);
    c->txts->fl_txt->img = mlx_xpm_file_to_image(c->mlx, "img/floor.xpm", &c->txts->fl_txt->width, &c->txts->fl_txt->height);
    if (c->txts->fl_txt->img == NULL)
    {
        return (terminator2(c, ERR_MLX_XPM_GEN));
    }
	c->txts->fl_txt->addr = mlx_get_data_addr(c->txts->fl_txt->img, &c->txts->fl_txt->bits_per_pixel, &c->txts->fl_txt->line_length,
                        			&c->txts->fl_txt->endian);
    c->txts->key_txt->img = mlx_xpm_file_to_image(c->mlx, "img/key.xpm", &c->txts->key_txt->width, &c->txts->key_txt->height);
    if (c->txts->key_txt->img == NULL)
    {
        return (terminator2(c, ERR_MLX_XPM_GEN));
    }
	c->txts->key_txt->addr = mlx_get_data_addr(c->txts->key_txt->img, &c->txts->key_txt->bits_per_pixel, &c->txts->key_txt->line_length,
                        			&c->txts->key_txt->endian);
    c->txts->dr_txt->img = mlx_xpm_file_to_image(c->mlx, "img/door.xpm", &c->txts->dr_txt->width, &c->txts->dr_txt->height);
    if (c->txts->dr_txt->img == NULL)
    {
        return (terminator2(c, ERR_MLX_XPM_GEN));
    }
	c->txts->dr_txt->addr = mlx_get_data_addr(c->txts->dr_txt->img, &c->txts->dr_txt->bits_per_pixel, &c->txts->dr_txt->line_length,
                        			&c->txts->dr_txt->endian);
    c->txts->kt_txt->img = mlx_xpm_file_to_image(c->mlx, "img/knight.xpm", &c->txts->kt_txt->width, &c->txts->kt_txt->height);
    if (c->txts->kt_txt->img == NULL)
    {
        return (terminator2(c, ERR_MLX_XPM_GEN));
    }
	c->txts->kt_txt->addr = mlx_get_data_addr(c->txts->kt_txt->img, &c->txts->kt_txt->bits_per_pixel, &c->txts->kt_txt->line_length,
                        			&c->txts->kt_txt->endian);
    return (SUCCESS);
}
