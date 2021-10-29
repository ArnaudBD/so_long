#include "includes/so_long.h"

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

    return (1);
}

// mlx_utils.c
int    start_mlx(t_config *c)
{
    c->mlx = mlx_init();
    if (c->mlx == NULL)
        return (FAILURE);
//mlx_get_screen_size()
    c->mlx_win = mlx_new_window(c->mlx, (c->size_map.x + 1)* ZOOM, (c->size_map.y + 1) * ZOOM, "so_long");
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
    c->wl_txt->img = mlx_xpm_file_to_image(c->mlx, "img/wall.xpm", &c->wl_txt->width, &c->wl_txt->height);
;
    if (c->wl_txt->img == NULL)
    {
        terminator(c);  // ajouter destruction texture
        return (FAILURE);
    }
	c->wl_txt->addr = mlx_get_data_addr(c->wl_txt->img, &c->wl_txt->bits_per_pixel, &c->wl_txt->line_length,
                        			&c->wl_txt->endian);
    
    return (SUCCESS);
}


// main.c
int main(int argc, const char *argv[])
{
	// void	    *mlx;
	// void    	*mlx_win;
	t_data  	img;
    t_txt     	wl_txt;
    t_config    c;

    c.img = &img;
    c.wl_txt = &wl_txt;
    init_struct_config(&c);
    if (parsing(argc, argv, &c) == FAILURE)
        return (FAILURE);
    show_list(&c);
    if (create_map(&c) != SUCCESS)
        return (FAILURE);
    show_map(&c);
    if (start_mlx(&c) != SUCCESS)
        return (FAILURE);
    map_drawer(&c);
	// img.img = mlx_new_image(mlx, RES_X, RES_Y);
    // if (!mlx_new_image)
    //     terminator();
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	//							&img.endian);
    // if (!mlx_get_data_addr)
    //     terminator();
    // c.mlx_win = mlx_win;
    // c.mlx = mlx;
    // fill_color(&img, BLACK);
    // mlx_put_image_to_window(c.mlx, c.mlx_win, c.img->img, 0, 0);
    // mlx_mouse_hook(c.mlx_win, fonction_enregistee_pour_souris, &c);
    if (mlx_key_hook(c.mlx_win, key_hook, &c) == FAILURE)
        return (FAILURE);
    mlx_loop(c.mlx);
    terminator2(&c, 0);
    return (1);
}