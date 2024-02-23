#ifndef STRUCTURES_H
# define STRUCTURES_H

// 기존 구조체
typedef enum e_bool    t_bool;
typedef enum e_object_type  t_object_type;

# define LIGHT_POINT 1
# define LUMEN 3

# define EPSILON 1e-6 // 0.000001

typedef struct s_vec3      t_vec3;
typedef struct s_vec3      t_point3;
typedef struct s_vec3      t_color3;

typedef struct s_ray        t_ray;

typedef struct s_viewport   t_viewport;
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;
typedef struct s_hit_record t_hit_record;
typedef struct s_scene  t_scene;

typedef struct s_object t_object;
typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;

typedef struct s_light  t_light;

enum  e_bool
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
    double x;
    double y;
    double z;
};

struct s_ray
{
    t_point3    orig;
    t_vec3    dir;
};

struct s_viewport
{
    double    viewport_h; // 뷰포트 세로길이
    double    viewport_w; // 뷰포트 가로길이
    t_vec3    horizontal; // 수평길이 벡터
    t_vec3    vertical; // 수직길이 벡터
    double    focal_len; // focal length
    t_point3    left_bottom; // 왼쪽 아래 코너점
};

struct  s_camera
{
    t_point3    origin;  // 카메라 원점(위치)
    t_vec3    vector;
    double    pov;
    t_viewport  viewport;
};

struct  s_canvas
{
    int  width; //canvas width
    int  height; //canvas height;
    double  aspect_ratio; //종횡비
};

struct s_hit_record
{
    t_point3    p;     // 교점의 좌표
    t_vec3    normal;  // 교점에서의 법선
    double    tmin;
    double    tmax;
    double    t;     // 광선의 원점과 교점 사이의 거리
    t_bool    front_face; // 카메라가 구의 내부에 위치하는지 여부
    t_color3    albedo;  // 반사율
};

struct  s_scene
{
    t_canvas         canvas;
    t_camera         camera;
    t_object         *world;
    t_light *light;
    t_color3         ambient;
    t_ray         ray;
    t_hit_record    rec;
};

struct  s_sphere
{
    t_point3    center;
    double    radius;
    double    radius2;
    t_color3    color;
};

struct  s_plane
{
    t_point3    point;
    t_vec3    normal;
    t_color3    color;
};

struct s_cylinder
{
    t_point3    point;
    t_vec3    vector;
    double    radius;
    double    height;
    t_color3    color;
};

struct  s_object
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

#endif
