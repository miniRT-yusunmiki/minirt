#ifndef MINRT_H
# define MINRT_H

# include "../lib/include/libft.h"
# include "../mlx/mlx.h"
# include "structures.h"

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

// hit
t_bool			hit_cylinder(t_cylinder *cy, t_ray *ray, t_hit_record *rec);
t_bool			hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec);
t_bool			hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec);
t_bool			hit(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool			hit_obj(t_object *world, t_ray *ray, t_hit_record *rec);
void			set_face_normal(t_ray *r, t_hit_record *rec);

// light
t_bool			in_shadow(t_scene *scene, t_light *light, t_hit_record *rec);
t_color3		get_diffuse(t_hit_record *rec, t_light *light);

// parse
void			parse_line(t_scene *scene, char *s, t_cnt *cnt);
void			init_cnt(t_cnt *cnt);
void			check_id_cnt(t_cnt cnt);
void			parse_file(t_scene *scene, char *file_name);

t_sphere		*set_sphere(char **elem);
t_plane			*set_plane(char **elem);
t_cylinder		*set_cylinder(char **elem);

t_color3		set_ambient(char **elem);
t_camera		set_camera(char **elem);
t_viewport		set_viewport(t_canvas canvas, t_camera cam);
t_light			*set_light(char **elem);

t_bool			is_rt_file(char *arg1);
void			check_arg(int argc, char **argv);
void			parse_file(t_scene *scene, char *file_name);
t_canvas		set_canvas(int width, int height);
t_mlxinfo		*set_mlx(int width, int height, t_scene *scene);
t_scene 		*set_scene(char *file_name);

// pixel
void			cam_dir_change(int keycode, t_mlxinfo *mlx_info);
void			cam_move(int keycode, t_mlxinfo *mlx_info);
int				exit_hook(void);
int				key_hook(int keycode, t_mlxinfo *mlx_info);
int				rgb_to_int(t_color3 pixel_color);
void			my_mlx_pixel_put(t_scene *scene, int x, int y, t_color3	pixel_color);
void			put_ray_pixel(int y, int x, t_scene *scene, int dummy);

// util
char			*get_next_line(int fd);

t_object		*object(t_object_type type, void *elementm);
void			oadd(t_object **list, t_object *new);
void			ladd(t_light **list, t_light *new);

int				sign_check(const char *s, int *i);
double			ft_atof(const char *s);
t_vec3			get_vector(char *s);
t_point3		get_point(char *s);
t_color3		get_color(char *s);

int				count_elem(char **elem);
int         	count_comma(char *s);
void			free_arr(char **arr);

// utils - vec_utils.c
t_vec3		    vec3(double x, double y, double z);
t_point3        point3(double x, double y, double z);
t_color3    	color3(double r, double g, double b);
double 		    vlength(t_vec3 vec);
double  		vlength2(t_vec3 vec);
t_vec3	    	vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		    vminus(t_vec3 vec, t_vec3 vec2);
t_vec3			vmults(t_vec3 vec, double t);
t_vec3			vmultv(t_vec3 vec, t_vec3 vec2);
double		    vdot(t_vec3 vec, t_vec3 vec2);
t_vec3  		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3	    	vunit(t_vec3 vec);
t_vec3			vdivide(t_vec3 vec, double t);
t_vec3  		vmin(t_vec3 vec1, t_vec3 vec2);

// ray
t_ray       	ray_primary(t_scene *scene, double u, double v);
t_point3		ray_at(t_ray *ray, double t);
t_color3    	ray_color(t_scene *scene);
void			shoot_ray(t_scene *scene, int dummy);

void			print_info(t_scene *scene);

#endif
