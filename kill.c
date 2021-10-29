# include "includes/so_long.h"

int terminator(t_config *c) /*, int error AVEC CODES D'ERREUR CORRESPONDANTS)*/
{
    t_list  *current;
    // if (error)
    // put_error(error);
    current = c->lines;
    if (c->img->img != NULL)
        mlx_destroy_image(c->mlx, c->img->img);
    if (c->mlx_win != NULL)
        mlx_destroy_window(c->mlx, c->mlx_win);
    if (c->mlx != NULL)
    {
        mlx_destroy_display(c->mlx);
        free(c->mlx);
        
    }
    while (current)
    {
        current = c->lines->next;
        free(c->lines);
        write(1, "OK\n", 1);
    }
    // if (c->map != NULL)
    //     free_tab(c->map);
    return (FAILURE);
}

void    display_error(int code)
{
    printf("so_long: ERROR - ");
    if (code == ERR_ARGC)
        printf("wrong argument count\n");
    else if (code == ERR_ARGV)
        printf("wrong file name\n");
    else if (code == ERR_OPEN)
        printf("could not open() file\n");
    else if (code == ERR_MAP)
        printf("wrong map design\n");
    else if (code == ERR_MAP_MALLOC)
        printf("Malloc error while creating map\n");
    else if (code == ERR_MAP_LINE_MALLOC)
        printf("Malloc error while creating the linked chain\n");
    else if (code == ERR_DRAWING)
        printf("Error while drawing the map\n");
    else if (code == ERR_NAME)
        printf("The file has a wrong name\n");
    else if (code == ERR_READ)
        printf("Cannot read\n");


}

// void    free_tab(t_config *c)
// {
//     c->
// }

int terminator2(t_config *c, int code)
{
    t_list  *current;
    // if (error)
    // put_error(error);
    // if (c->img->img)
    //     mlx_destroy_image(c->mlx, c->img->img);
    // if (c->mlx_win)
    //     mlx_destroy_window(c->mlx, c->mlx_win);
    // if (c->mlx)
    //     mlx_destroy_display(c->mlx);
    current = c->lines;
    if (c->img->img != NULL)
        mlx_destroy_image(c->mlx, c->img->img);
    if (c->mlx_win != NULL)
        mlx_destroy_window(c->mlx, c->mlx_win);
    if (c->mlx != NULL)
    {
        mlx_destroy_display(c->mlx);
        free(c->mlx);
    }
    while (current)
    {
        current = c->lines->next;
        free(c->lines->data);
        free(c->lines);
        c->lines = current;
    }
    if (c->map)
        free(c->map);
    if (code != 0)
    {
        display_error(code);
        return (FAILURE);
    }
    return (SUCCESS);
}
