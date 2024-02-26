#include "../include/minirt.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec3	L;
	double	d;
	double	Tca;
	double	Tnc;

	L = vminus(sp->center, ray->orig);
	Tca = vdot(ray->dir, L);
	if (Tca < 0)
		return (FALSE);
	d = sqrt(vlength2(L) - pow(Tca, 2));
	// printf("d : %lf\n", d);
	if (d > sp->radius)
		return (FALSE);
	Tnc = sqrt(pow(sp->radius, 2) - pow(d, 2));
	rec->t = Tca - Tnc;
	// printf("%f\n", rec->t);
	rec->p = vplus(ray->orig, vmult(ray->dir, rec->t));
	rec->normal = vminus(rec->p, sp->center);
	rec->albedo = sp->color;
	return (TRUE);
}

// t_bool      hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
// {
// 	t_vec3  oc; //방향벡터로 나타낸 구의 중심.
// 	//a, b, c는 각각 t에 관한 2차 방정식의 계수
// 	double  a;
// 	double  half_b;
// 	double  c;
// 	double  discriminant; //판별식
// 	double	sqrtd;
// 	double	root;

// 	oc = vminus(ray->orig, sp->center);
// 	a = vlength2(ray->dir);
// 	half_b = vdot(oc, ray->dir);
// 	c = vlength2(oc) - sp->radius2;
// 	discriminant = half_b * half_b - a * c;

// 	if (discriminant < 0)
// 		return (FALSE);
// 	sqrtd = sqrt(discriminant);
// 	root = (-half_b - sqrtd) / a; // 두 실근 중에 더 가까운 값부터 확인
// 	if (root < rec->tmin || root > rec->tmax)
// 	{
// 		root = (-half_b + sqrtd) / a; // 만약 음수이면 다른 실근값도 확인
// 		if (root < rec->tmin || root > rec->tmax)
// 			return (FALSE);
// 	}
// 	rec->t = root;
// 	rec->p = vplus(ray->orig, vmult(ray->dir, rec->t));
// 	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 법선벡터 정규화
// 	// set_face_normal(ray, rec); // 카메라가 구의 내부에 있는지 여부 설정
// 	rec->albedo = sp->color;
// 	return (TRUE);
// }
