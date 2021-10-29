# include "includes/so_long.h"

void    fill_color(t_data *img, int color)
{
    int x = 0;
    int y = 0;
    while (y < RES_Y)
    {
        x = 0;
        while (x < RES_X)
        {
            my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
}

int key_hook(int keycode, t_config *c)
{
    if (keycode == 65307)
    {
        terminator2(c, 0);
        exit(SUCCESS);
    }
    else if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
    {
        move(c, keycode);
        map_drawer(c);
        mlx_put_image_to_window(c->mlx, c->mlx_win, c->img->img, 0, 0);
    }
    if (c->on_exit == TRUE
    && c->collected == c->collectibles)
    {
        terminator2(c, 0);
        exit(SUCCESS);
    }
    return (1);
}
