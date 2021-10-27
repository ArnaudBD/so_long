# include "includes/so_long.h"

int add_line_in_lines(char *line, t_config *c)
{
    t_list  *new;
    new = malloc(sizeof(*new));
    if (new == NULL)
        return (FAILURE);
    new->next = c->lines;
    new->data = line;
    c->lines = new;
    return (SUCCESS);
}

int map_size_calculator(t_config *c)
{
    // t_pt    *map_size;
    t_list  *current;

    // map_size = NULL;
    c->size_map.x = -1;
    c->size_map.y = 0;
    c->size_map.x += ft_strlen((char *)c->lines->data);
    current = c->lines;
    c->size_map.y = 0;
    while (current->next)
    {
        c->size_map.y++;
        current = current->next;
    }
    return (SUCCESS);
}

int create_map(t_config *c)
{
    int     i;
    t_list  *current;
    int     map_size;

    i = 0;
    current = c->lines;
    map_size_calculator(c);
    map_size = (c->size_map.y + 1) * (c->size_map.x + 2) + 1;
printf("map size == %d\n", map_size);
    (c->map) = malloc(sizeof(char) * map_size);
    if (c->map == NULL)
        return (terminator2(c, ERR_MAP_MALLOC));
    while (current)
    {
write(1, "ICI\n", 4);
        (c->map)[i] = current->data;
        i++;
        current = current->next;
write(1, "LA\n", 3);
    }
    i = 56;
    while (i)
    {
        c->map[map_size - i] = 0;
        printf("%d\n", i--);
    }
    return (SUCCESS);
}

void show_list(t_config *c)
{
    t_list *current;

    current = c->lines;
    while (current)
    {
        printf("|%s|\n", (char *)current->data);
        current = current->next;
    }
}

void    show_map(t_config *c)
{
    int i;

    i = 0;
    while (c->map[i])
    {
        printf("|%s|\n", c->map[i++]);
    }
    write(1, "FIN\n", 4);
}