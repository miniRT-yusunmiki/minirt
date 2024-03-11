#include "../../include/minirt.h"

t_object    *object(t_object_type type, void *element)
{
    t_object    *new;

    if (!(new = (t_object *)malloc(sizeof(t_object))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->next = NULL;
    return (new);
}

void        oadd(t_object **list, t_object *new)
{
    t_object    *cur;

    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    cur = *list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}

void	ladd(t_light **list, t_light *new)
{
    t_light    *cur;

    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    cur = *list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}

void    free_list(t_object *world)
{
    t_object    *tmp;

    while (world)
    {
        free(world->element);
        tmp = world->next;
        free(world);
        world = tmp;
    }
}
