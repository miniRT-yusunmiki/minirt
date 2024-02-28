#include "../include/minirt.h"

t_bool  check_shadow(t_scene *scene, t_light *light)
{
    t_vec3          light_dir;
    t_hit_record    shadow_rec;
    t_ray           p_to_light;

    light_dir = vminus(light->origin, scene->rec.p);
    shadow_rec.tmin = 0;
    shadow_rec.tmax = vlength(light_dir);
    p_to_light.orig = scene->rec.p;
    p_to_light.dir = vunit(light_dir);
    if (hit(scene->world, &p_to_light, &shadow_rec))
        return (TRUE);
    return (FALSE);
}

t_color3    get_diffuse(t_hit_record rec, t_light *light)
{
    t_color3    diffuse;
    t_vec3    light_dir;
    double    diff;

    light_dir = vunit(vminus(light->origin, rec.p));     // 점에서 광원으로의 방향벡터
    diff = fmax(0.0, vdot(light_dir, rec.normal));     // light_dir와 법선벡터의 내적값, 두 벡터의 차이
    diffuse = vmult(vmult(light->color, diff), light->ratio);
    return (diffuse);
}

t_color3    phong_light(t_scene *scene)
{
    t_color3    light_result;
    t_color3    ambient;
    t_color3    diffuse;

    ambient = scene->ambient;
    if (check_shadow(scene, scene->lights))
        return (vmult_(ambient, scene->rec.color));
        // return (color3(0,0,255));
    diffuse = get_diffuse(scene->rec, scene->lights);
    light_result = vplus(ambient, diffuse);
    // printf("%lf %lf %lf\n", scene->rec.color.x, scene->rec.color.y, scene->rec.color.z);
    // printf("%lf %lf %lf\n", vmult_(light_result, scene->rec.color).x, vmult_(light_result, scene->rec.color).y, vmult_(light_result, scene->rec.color).z);
    return (vmin(vmult_(light_result, scene->rec.color), color3(1, 1, 1)));
}
