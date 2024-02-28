#include "../include/minirt.h"

t_color3    get_diffuse(t_scene *scene, t_light *light)
{
    t_color3    diffuse;
    t_vec3      light_dir;
    double      diff;

    light_dir = vunit(vminus(light->origin, scene->rec.p));     // 점에서 광원으로의 방향벡터
    diff = fmax(0.0, vdot(light_dir, scene->rec.normal));       // light_dir와 법선벡터의 내적값, 두 벡터의 차이
    diffuse = vmult(vmult(light->color, diff), light->ratio);
    return (diffuse);
}

t_color3    phong_light(t_scene *scene)
{
    t_color3    light_result;
    t_color3    ambient;
    t_color3    diffuse;

    ambient = scene->ambient;
    diffuse = get_diffuse(scene, scene->lights);
    light_result = vplus(ambient, diffuse);
    // printf("%lf %lf %lf\n", scene->rec.color.x, scene->rec.color.y, scene->rec.color.z);
    // printf("%lf %lf %lf\n", vmult_(light_result, scene->rec.color).x, vmult_(light_result, scene->rec.color).y, vmult_(light_result, scene->rec.color).z);
    return (vmin(vmult_(light_result, scene->rec.color), color3(1, 1, 1)));
}
