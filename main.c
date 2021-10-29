#include "includes/so_long.h"

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
    mlx_mouse_hook(c.mlx_win, fonction_enregistee_pour_souris, &c);
    if (mlx_key_hook(c.mlx_win, key_hook, &c) == FAILURE)
        return (FAILURE);
    mlx_loop(c.mlx);
    terminator2(&c, 0);
    return (1);
}