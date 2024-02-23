#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef	struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;
typedef	struct s_canvas t_canvas;
typedef	struct s_camera	t_camera;
typedef struct s_viewport t_viewport;
typedef	struct s_mlxinfo t_mlxinfo;
typedef	struct s_scene t_scene;
typedef struct s_object t_object;
typedef struct s_light t_light;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;

typedef	int	t_bool;
# define FALSE 0;
# define TRUE 1;

#define _USE_MATH_DEFINES

typedef int t_object_type;
# define SP 0
# define PL 1

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_camera
{
	t_point3    orig;
	double		fov;
	t_vec3		dir;
	t_vec3		right;
	t_vec3		up;
	t_viewport	viewport;
};

struct s_viewport
{
	double      height;
    double      width;
    double      focal_len;
	t_point3    left_upper;
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
};

struct s_scene
{
	t_mlxinfo	*mlxinfo;
	t_canvas	canvas;
	t_camera	*camera;
	t_object	*world;
	t_light		*lights;
	t_color3	ambient;
};

struct s_object
{
    t_object_type   type;
    void            *element;
    void            *next;
};

struct s_light
{
    t_point3    origin;
    t_color3    color;
    double      ratio;
	t_light		*next;
};

struct s_sphere
{
    t_point3    center;
    double      radius;
    double      radius2;
	t_color3	color;
};

struct s_plane
{
    t_point3    point;
    t_vec3      normal;
	t_color3	color;
};

struct s_cylinder
{
	t_point3	center;
	t_vec3		normal;
	double		diameter;
	double		height;
	t_color3	color;
};

#endif