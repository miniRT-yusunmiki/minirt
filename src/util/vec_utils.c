#include "../../include/minirt.h"

//vec3 create
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

//point3 create
t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

//color3 create
t_color3	color3(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}

//vector length
double 	vlength(t_vec3 vec)
{
	return (sqrt(vlength2(vec)));
}

double		vlength2(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

//vector plus
t_vec3	vplus(t_vec3 vec, t_vec3 vec2)
{
	vec.x += vec2.x;
	vec.y += vec2.y;
	vec.z += vec2.z;
	return (vec);
}

//vector minus
t_vec3	vminus(t_vec3 vec, t_vec3 vec2)
{
	vec.x -= vec2.x;
    vec.y -= vec2.y;
    vec.z -= vec2.z;
    return (vec);
}

//vector scala mult
t_vec3	vmults(t_vec3 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

//vector vector mult
t_vec3	vmultv(t_vec3 vec, t_vec3 vec2)
{
    vec.x *= vec2.x;
    vec.y *= vec2.y;
    vec.z *= vec2.z;
    return (vec);
}

//vector in 
double	vdot(t_vec3 vec, t_vec3 vec2)
{
    return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

//vector out
t_vec3	vcross(t_vec3 vec, t_vec3 vec2)
{
    t_vec3	new;

    new.x = vec.y * vec2.z - vec.z * vec2.y;
    new.y = vec.z * vec2.x - vec.x * vec2.z;
    new.z = vec.x * vec2.y - vec.y * vec2.x;
    return (new);
}

//unit vector
t_vec3	vunit(t_vec3 vec)
{
    double	len;
	
	len = vlength(vec);
    // if (len == 0)
    // {
    //     printf("Error\n:Devider is 0");
    //     exit(0);
    // }
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
    return (vec);
}

t_vec3	vdivide(t_vec3 vec, double t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;

    return vec;
}

t_vec3  vmin(t_vec3 vec1, t_vec3 vec2)
{
    if (vec1.x > vec2.x)
        vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
        vec1.z = vec2.z;
    return (vec1);
}
