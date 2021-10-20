# include "includes/so_long.h"

int terminator(t_config *c) /*, int error AVEC CODES D'ERREUR CORRESPONDANTS)*/
{
    // if (error)
    // put_error(error);
    if (c->img->img != NULL)
        mlx_destroy_image(c->mlx, c->img->img);
    if (c->mlx_win != NULL)
        mlx_destroy_window(c->mlx, c->mlx_win);
    if (c->mlx != NULL)
    {
        mlx_destroy_display(c->mlx);
        free(c->mlx);
        
    }
    // if (c->map != NULL)
    //     free_tab(c->map);
    return (FAILURE);
}
