# include "includes/so_long.h"

// int put_wall(t_config *c, int x, int y, char ch)
// {
//     char    *relative_path = "./img/wall.xpm";
//     int     img_width;
//     int     img_height;

//     img_height = ZOOM;
//     img_width = ZOOM;
//     c->img->img = mlx_xpm_file_to_image(c->mlx, relative_path, &img_width, &img_height);
//     my_mlx_image_put()
//     return (SUCCESS);
// }

int draw_the_square(t_config *c, int x, int y, char ch)
{
   int  i;
   int  j;

// if (ch == '1')
//     return (put_wall(c, x, y, ch));
    j = 0;
    x *= ZOOM;
    y *= ZOOM;
    if ((x < (RES_X - ZOOM)) && (y < (RES_Y - ZOOM)))
    {
        while (j < ZOOM)
        {
            i = 0;
            while (i < ZOOM)
            {
                if (ch == '1')
                    my_mlx_pixel_put(c->img, x + i, y + j, RED);
                else if (ch == '0')
                    my_mlx_pixel_put(c->img, x + i, y + j, BLUE);
                else if (ch == 'P')
                    my_mlx_pixel_put(c->img, x + i, y + j, WHITE);
                else if (ch == 'E' || ch == 'O')
                    my_mlx_pixel_put(c->img, x + i, y + j, GREEN);
                else if (ch == 'C')
                    my_mlx_pixel_put(c->img, x + i, y + j, GREY);
                i++;
            }
            j++;
        }
    }
    return (SUCCESS);
}

int draw_the_texture(t_config *c, int x, int y, t_txt *txt)
{
   int  i;
   int  j;
   int  pixel;

// if (ch == '1')
//     return (put_wall(c, x, y, ch));
    j = 0;
    x *= ZOOM;
    y *= ZOOM;
    while (j < ZOOM)
    {
        i = 0;
        while (i < ZOOM)
        {
            pixel = get_pixel(txt, i, j);
            my_mlx_pixel_put(c->img, x + i, y + j, pixel);
            i++;
        }
        j++;
    }
    return (SUCCESS);
}

int map_drawer(t_config *c)
{
    int x;
    int y;

    y = 0;
    while (y <= c->size_map.y)
    {
        x = 0;
        while (x <= c->size_map.x)
        {
            if (c->map[y][x] == '1')
                draw_the_texture(c, x, y, c->wl_txt);
            if (c->map[y][x] == '0')
                draw_the_texture(c, x, y, c->wl_txt);
            if (c->map[y][x] == 'P')
                draw_the_texture(c, x, y, c->wl_txt);
            if (c->map[y][x] == 'E')
                draw_the_texture(c, x, y, c->wl_txt);
            if (c->map[y][x] == 'C')
                draw_the_texture(c, x, y, c->wl_txt);

                else if (draw_the_square(c, x, y, c->map[y][x]) == FAILURE)
                    return (terminator2(c, ERR_DRAWING));
                if (c->map[y][x] == 'P')
                {
                    c->player.x = x;
                    c->player.y = y;
                }
                if (c->map[y][x] == 'E')
                {
                    c->exit.x = x;
                    c->exit.y = y;
                }
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(c->mlx, c->mlx_win, c->img->img, 0, 0);
    return (SUCCESS);
}