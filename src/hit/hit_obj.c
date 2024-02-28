#include "../../include/minirt.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	// ray와 법선벡터의 내적이 음수이면 카메라가 물체 외부, 양수이면 물체 내부에 위치한다
	rec->front_face = TRUE;
	if (vdot(ray->dir, rec->normal) < 0)
		rec->front_face = FALSE;
	// 카메라가 물체 내부에 위치하면 법선벡터를 반대 방향으로 설정
	if (rec->front_face)
		rec->normal = vmult(rec->normal, -1);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	double	tca;
	double	thc;
	double	d;
	t_vec3	L;
	double	t;
 
	L = vminus(sp->center, ray->orig);
	tca = vdot(ray->dir, L);
	if (tca < 0)
		return (FALSE);
	d = sqrt(vlength2(L) - pow(tca, 2));
	if (d > sp->radius)
		return (FALSE);
	thc = sqrt(sp->radius2 - pow(d, 2));
	t = tca - thc;
	if (t < rec->tmin || t > rec->tmax)
	{
		t = tca + thc; // 만약 음수이면 다른 실근값도 확인
		if (t < rec->tmin || t > rec->tmax)
			return (FALSE);
	}
	rec->t = t;
	rec->p = ray_at(ray, rec->t);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->color = sp->color;
	return (TRUE);
}

t_bool	hit_plane(t_plane *pl, t_ray *ray, t_hit_record *rec)
{
	double	num;
	double	den;
	double	t;

	num = vdot(vminus(pl->point, ray->orig), pl->normal);
	den = vdot(ray->dir, pl->normal);
	if (fabs(den) < 0) 
		return (FALSE);
	t = num / den;
	if (t < rec->tmin || t > rec->tmax)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = pl->normal;
	set_face_normal(ray, rec);
	rec->color = pl->color;
	return (TRUE);
}
