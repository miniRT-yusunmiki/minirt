/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusung <yusung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:25:23 by yusung            #+#    #+#             */
/*   Updated: 2024/03/09 18:36:42 by yusung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define WRONG_INFO	-999
# define EPSILON 1e-6

typedef enum e_bool			t_bool;
typedef enum e_object_type	t_object_type;

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;

typedef struct s_ray		t_ray;

typedef struct s_canvas		t_canvas;
typedef struct s_camera		t_camera;
typedef struct s_viewport	t_viewport;
typedef struct s_mlxinfo	t_mlxinfo;
typedef struct s_hit_record	t_hit_record;
typedef struct s_light		t_light;
typedef struct s_scene		t_scene;
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_formula	t_formula;

typedef struct s_cnt		t_cnt;

enum e_bool
{
	FALSE,
	TRUE
};

enum e_object_type
{
	SP,
	PL,
	CY
};

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_camera
{
	t_point3	orig;
	double		fov;
	t_vec3		dir;
	t_vec3		right;
	t_vec3		up;
};

struct s_viewport
{
	double		height;
	double		width;
	double		focal_len;
	t_point3	left_upper;
};

struct s_light
{
	t_point3	origin;
	t_color3	color;
	double		ratio;
};

struct s_mlxinfo
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		pbits;
	int		len;
	int		endian;
	t_scene	*scene;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_vec3		light_dir;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	color;
};

struct s_scene
{
	t_mlxinfo		*mlxinfo;
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_light			light;
	t_color3		ambient;
	t_viewport		viewport;
	t_ray			ray;
	t_hit_record	rec;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
};

struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
	t_color3	color;
};

struct s_plane
{
	t_point3	point;
	t_vec3		normal;
	t_color3	color;
};

struct s_cylinder
{
	t_point3	top_center;
	t_point3	bottom_center;
	t_vec3		normal;
	double		radius;
	double		height;
	t_color3	color;
};

struct s_formula
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
};

struct s_cnt
{
	int	a;
	int	c;
	int	l;
};

#endif
