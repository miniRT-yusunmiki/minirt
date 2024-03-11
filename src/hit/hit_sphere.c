#include "../../include/minirt.h"

static void	ft_swap(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool	sp_calculate(t_sphere *sp, t_ray *ray, t_sp_cal *sp_cal)
{
	sp_cal->L = vminus(sp->center, ray->orig);
	sp_cal->tca = vdot(sp_cal->L, ray->dir);
	sp_cal->d = sqrt(vlength2(sp_cal->L) - pow(sp_cal->tca, 2));
	if (sp_cal->d > sp->radius)
		return (FALSE);
	sp_cal->thc = sqrt(sp->radius2 - pow(sp_cal->d, 2));
	return (TRUE);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_sp_cal	sp_cal;
	double		t[2];
	double		root;
 
	if (sp_calculate(sp, ray, &sp_cal) == FALSE)
		return (FALSE);
	t[0] = sp_cal.tca - sp_cal.thc;
	t[1] = sp_cal.tca + sp_cal.thc;
	if (t[0] > t[1])
		ft_swap(&t[0], &t[1]);
	root = t[0];
	if (root < rec->tmin || root >= rec->tmax)
	{
		root = t[1];
		if (root < rec->tmin || root >= rec->tmax)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(vminus(rec->p, sp->center));
	rec->color = sp->color;
	set_face_normal(ray, rec);
	return (TRUE);
}
