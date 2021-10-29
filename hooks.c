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

int     fonction_enregistee_pour_souris(int button, int x, int y, t_config *c)
{
printf("souris x = %d\n", x);
printf("souris y = %d\n", y);
printf("souris b = %d\n", button);
    int i;
    int j;

    i = 0;
    j = 0;
    (void)button;
    if ((x < (RES_X - 10)) && (y < (RES_Y - 10)))
    {
        while (j < 10)
        {
            i = 0;
            while (i < 10)
            {
                if (button == 1)
                    my_mlx_pixel_put(c->img, x + i, y + j, RED);
                else if (button == 2)
                    my_mlx_pixel_put(c->img, x + i, y + j, BLUE);
                else
                    my_mlx_pixel_put(c->img, x + i, y + j, WHITE);


                i++;
            }
            j++;
        }
    }
    mlx_put_image_to_window(c->mlx, c->mlx_win, c->img->img, 0, 0);

    return (1);
}