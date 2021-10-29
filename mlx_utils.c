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
