#include "includes/so_long.h"


// mlx_utils.c
void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// hooks.c
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

    return (MES_COUILLES);
}

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


int fonction_enregistree_pour_clavier(int keycode, t_config *c)
{
    if (keycode == 'w' || keycode == 's' || keycode == 'd' || keycode == 'a' )
    {
        if (keycode == 'w')
            fill_color(c->img, BLUE);
        else if (keycode == 's')
            fill_color(c->img, RED);
        else if (keycode == 'a')
            fill_color(c->img, GREEN);
        else if (keycode == 'd')
            fill_color(c->img, WHITE);
        mlx_put_image_to_window(c->mlx, c->mlx_win, c->img->img, 0, 0);
    }

    printf("touche entree = %d\n", keycode);
    return (MES_COUILLES);
}

// mlx_utils.c
int    start_mlx(t_config *c)
{
    c->mlx = mlx_init();
    if (c->mlx == NULL)
        return (FAILURE);
    c->mlx_win = mlx_new_window(c->mlx, RES_X, RES_Y, "so_long");
 //  c->mlx_win = NULL;
    if (c->mlx_win == NULL)
    {
        terminator(c);
        return (FAILURE);
    }
    c->img->img = mlx_new_image(c->mlx, RES_X, RES_Y);
    if (c->img->img == NULL)
    {
        terminator(c);
        return (FAILURE);
    }
	c->img->addr = mlx_get_data_addr(c->img->img, &c->img->bits_per_pixel, &c->img->line_length,
                        			&c->img->endian);
    return (SUCCESS);
}

// main.c
int main(int argc, const char *argv[])
{
	// void	    *mlx;
	// void    	*mlx_win;
	t_data  	img;
    t_config    c;

    c.img = &img;
    init_struct_config(&c);
    if (parsing(argc, argv, &c) == FAILURE)
        return (FAILURE);
    if (start_mlx(&c) != SUCCESS)
        return (FAILURE);
//	img.img = mlx_new_image(mlx, RES_X, RES_Y);
    // if (!mlx_new_image)
    //     terminator();
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	//							&img.endian);
    // if (!mlx_get_data_addr)
    //     terminator();
    // c.mlx_win = mlx_win;
    // c.mlx = mlx;
    fill_color(&img, BLACK);
    mlx_put_image_to_window(c.mlx, c.mlx_win, c.img->img, 0, 0);
    mlx_mouse_hook(c.mlx_win, fonction_enregistee_pour_souris, &c);
    mlx_key_hook(c.mlx_win, fonction_enregistree_pour_clavier, &c);
    mlx_loop(c.mlx);
    terminator2(&c, 0);
    return (1);
}