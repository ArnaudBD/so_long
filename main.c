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
    c->txts->wl_txt->img = mlx_xpm_file_to_image(c->mlx, "img/wall.xpm", &c->txts->wl_txt->width, &c->txts->wl_txt->height);
    if (c->txts->wl_txt->img == NULL)
    {
        terminator(c);  // ajouter destruction texture
        return (FAILURE);
    }
	c->txts->wl_txt->addr = mlx_get_data_addr(c->txts->wl_txt->img, &c->txts->wl_txt->bits_per_pixel, &c->txts->wl_txt->line_length,
                        			&c->txts->wl_txt->endian);
    c->txts->fl_txt->img = mlx_xpm_file_to_image(c->mlx, "img/floor.xpm", &c->txts->fl_txt->width, &c->txts->fl_txt->height);
    if (c->txts->fl_txt->img == NULL)
    {
        terminator(c);  // ajouter destruction texture
        return (FAILURE);
    }
	c->txts->fl_txt->addr = mlx_get_data_addr(c->txts->fl_txt->img, &c->txts->fl_txt->bits_per_pixel, &c->txts->fl_txt->line_length,
                        			&c->txts->fl_txt->endian);
    c->txts->key_txt->img = mlx_xpm_file_to_image(c->mlx, "img/key.xpm", &c->txts->key_txt->width, &c->txts->key_txt->height);
    if (c->txts->key_txt->img == NULL)
    {
        terminator(c);  // ajouter destruction texture
        return (FAILURE);
    }
	c->txts->key_txt->addr = mlx_get_data_addr(c->txts->key_txt->img, &c->txts->key_txt->bits_per_pixel, &c->txts->key_txt->line_length,
                        			&c->txts->key_txt->endian);
    c->txts->dr_txt->img = mlx_xpm_file_to_image(c->mlx, "img/door.xpm", &c->txts->dr_txt->width, &c->txts->dr_txt->height);
    if (c->txts->dr_txt->img == NULL)
    {
        terminator(c);  // ajouter destruction texture
        return (FAILURE);
    }
	c->txts->dr_txt->addr = mlx_get_data_addr(c->txts->dr_txt->img, &c->txts->dr_txt->bits_per_pixel, &c->txts->dr_txt->line_length,
                        			&c->txts->dr_txt->endian);
    c->txts->kt_txt->img = mlx_xpm_file_to_image(c->mlx, "img/knight.xpm", &c->txts->kt_txt->width, &c->txts->kt_txt->height);
    if (c->txts->kt_txt->img == NULL)
    {
        terminator(c);  // ajouter destruction texture
        return (FAILURE);
    }
	c->txts->kt_txt->addr = mlx_get_data_addr(c->txts->kt_txt->img, &c->txts->kt_txt->bits_per_pixel, &c->txts->kt_txt->line_length,
                        			&c->txts->kt_txt->endian);
    
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
    if (init_struct_config(&c) == FAILURE)
        return (FAILURE);
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