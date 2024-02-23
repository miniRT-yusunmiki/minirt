#include "../include/minirt.h"

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
