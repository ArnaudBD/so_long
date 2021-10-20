#include "includes/so_long.h"
#include "includes/gnl.h"

int parse_line(char *line, t_config *c)
{
    int i;
    int len;

    i = 0;
    len = strlen(line);
    while (line[i])
    {
        if (line[i] != '1' && line[i] != '0' && line[i] != 'P' \
            && line[i] != 'E' && line[i] != 'C')
            return (FAILURE);
        if (line[0] != '1' || line[len - 1] != '1')
            return (FAILURE);
        if (line[i] == 'P' && c->player.x >= 0)
            return (FAILURE);
        else if (line[i] == 'P')
            c->player.x = i;
        if (line[i] == 'E')
            c->exit++;
        if (line[i] == 'C')
            c->collectibles++;
        i++;
    }
    return (SUCCESS);
}

int check_arg_name(char const *argv[], t_config *c)
{
    int i;
    char    *str;

    i = ft_strlen(argv[1]) - 4;
    str = ".ber";

    if (ft_strncmp((str), &argv[1][i], 5))
        return (terminator(c));
    return (SUCCESS);
}

int parsing(int argc, const char *argv[], t_config *c)
{
    int                 fd;
    char                *line;
    long unsigned int   len;

    len = 0;
    if (argc != 2 || argv[1] == NULL)
        return (terminator(c));
    if (check_arg_name(argv, c) == FAILURE)
        return (FAILURE);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (terminator(c));
    while (get_next_line(fd, &line) == 1)
    {
        if (parse_line(line, c) == FAILURE)
        {
            free(line);
            return (terminator(c));
        }
        if (len > 0 && len != strlen(line))
        {
            free(line);
            return (terminator(c));
        }
        len = strlen(line);
        free(line);
    }
    free(line);
    if (c->collectibles == 0 || c->exit != 1 || c->player.x == -1)
        return (FAILURE);
    return (SUCCESS);
}