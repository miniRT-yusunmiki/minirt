#ifndef MINRT_H
# define MINRT_H

# include "../lib/include/libft.h"
# include "../mlx/mlx.h"
# include "structures.h"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

void			check_arg(int argc, char **argv);

t_color3		parse_ambient_info(char **elem);
t_camera		parse_camera_info(char **elem);
t_viewport		set_viewport(t_canvas canvas, t_camera cam);
t_light			*parse_light_info(char **elem);

t_sphere		*parse_sphere_info(char **elem);
t_plane			*parse_plane_info(char **elem);
t_cylinder		*parse_cylinder_info(char **elem);

char			*get_next_line(int fd);

void			parse_file(t_scene *scene, char *file_name);

double			ft_atof(const char *s);
t_vec3			get_vector(char *s);
t_point3		get_point(char *s);
t_color3		get_color(char *s);
int				count_elem(char **elem);

t_scene 		*set_scene(char *file_name);

t_object		*object(t_object_type type, void *element);
void			oadd(t_object **list, t_object *new);
void			ladd(t_light **list, t_light *new);

void			free_arr(char **arr);

//utils - vec_utils.c
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(double r, double g, double b);
double 		vlength(t_vec3 vec);
double		vlength2(t_vec3 vec);
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec, double t);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);

#endif