#include "../../include/structures.h"
#include "../include/minirt.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_viewport	viewport(t_camera *cam, t_canvas *canvas)
{
	t_viewport	vp;
	t_point3	focus;
	t_point3	focus_left;

	vp.height = 2.0;
	vp.width = vp.height * canvas->aspect_ratio;
	vp.focal_len = (vp.width / 2) / tan((cam->fov * 0.5) * M_PI / 180);
	focus = vplus(vmult(cam->dir, vp.focal_len), cam->orig);
	focus_left = vminus(focus, vmult(cam->right, (vp.width * 0.5)));
	vp.left_upper = vplus(focus_left, cam->up);
	return (vp);
}

t_camera	*camera(t_canvas *canvas, t_point3 origin, t_vec3 dir, double fov)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->orig = origin;
	camera->fov = fov;
	camera->dir = dir;
	camera->right = vcross(vec3(0, 1, 0), camera->dir);
	camera->up = vcross(camera->right, camera->dir);
	camera->viewport = viewport(camera, canvas);
	return (camera);
}
