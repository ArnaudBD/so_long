#include "so_long.h"
#include <stdio.h>
#define RES_Y 1080
#define RES_X 1920
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define BLACK 0x0
#define WHITE 0xFFFFFF

#define MES_COUILLES 123

typedef struct  s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct  s_config
{
    void    *mlx;
    void    *mlx_win;
    t_data  *img;
    /* data */
}              t_config;



void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     fonction_enregistee_pour_souris(int button, int x, int y, t_config *c)
{
printf("souris x = %d\n", x);
printf("souris y = %d\n", y);
printf("souris b = %d\n", button);
    // int i;
    // int j;

    // i = 0;
    // j = 0;
    (void)button;
    // if ((x < RES_X - 10) &&(y < RES_Y - 10))
    // {
    //     while (j < 10)
    //     {
    //         i = 0;
    //         while (x < 10)
    //         {
                my_mlx_pixel_put(c->img, x, y, RED);
    //             i++;
    //         }
    //         j++;
    //     }
    // }
    mlx_put_image_to_window(c->mlx, c->mlx_win, c->img->img, x, y);

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

int	main(void)
{
	void	    *mlx;
	void    	*mlx_win;
	t_data  	img;
    t_config    c;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, RES_X, RES_Y, "Hello world!");
	img.img = mlx_new_image(mlx, RES_X, RES_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    c.mlx_win = mlx_win;
    c.mlx = mlx;
    c.img = &img;
    fill_color(&img, BLACK);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_mouse_hook(mlx_win, fonction_enregistee_pour_souris, &c);
    mlx_key_hook(mlx_win, fonction_enregistree_pour_clavier, &c);
    mlx_loop(mlx);
    return (1);
}