# include "includes/so_long.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length +
     x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// void    my_mlx_image_put(t_data *data, int x, int y, void *img)
// {
//     char    *dst;

//     dst = data->addr + (y * data->img)
// }