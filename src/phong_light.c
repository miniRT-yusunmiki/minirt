#include "../include/minirt.h"


t_color3    phong_light(t_scene *scene)
{
    t_color3 ambient;

    ambient = scene->ambient;
    return (vmin(vmult_(ambient, scene->rec.color), color3(1, 1, 1)));
}
