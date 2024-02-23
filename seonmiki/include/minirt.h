#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "structures.h"

//set - create.c
t_canvas	canvas(int width, int height);
t_viewport	viewport(t_camera *cam, t_canvas *canvas);
t_camera	*camera(t_canvas *canvs, t_point3 origin, t_vec3 dir, int pov);

//set - init.c
t_mlxinfo	*mlxinfo_init(int width, int height);
t_scene		*scene_init(int ac, char **av);

//utils - vec_utils.c
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
double 		vlength(t_vec3 vec);
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec, double t);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);

#endif