#include "../include/minirt.h"

t_canvas    canvas(int width, int height)
{
    t_canvas canvas;

    canvas.width = width;
    canvas.height = height;
    canvas.aspect_ratio = (double)width / (double)height;
    return (canvas);
}

t_scene *set_scene(char *file_name)
{
    t_scene *scene;

    if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    scene->canvas = canvas(1200, 900);
    scene->world = NULL;
    scene->light = NULL;
    parse_file(scene, file_name);
    return (scene);
}
