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
    perror("so_long: ERROR - ");
    if (code == ERR_ARGC)
        perror("wrong argument count\n");
    else if (code == ERR_ARGV)
        perror("wrong file name\n");
    else if (code == ERR_OPEN)
        perror("could not open() file\n");
}

int terminator2(t_config *c, int code)
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
    }
    // if (c->map != NULL)
    //     free_tab(c->map);
    if (code != 0)
    {
        display_error(code);
        return (FAILURE);
    }
    return (SUCCESS);
}