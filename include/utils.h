#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "structures.h"

// 생성자
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);

// 벡터 값 설정
void		vset(t_vec3 *vec, double x, double y, double z);

// 벡터 길이의 제곱
double		vlength2(t_vec3 vec);
// 벡터 길이
double		vlength(t_vec3 vec);

// 벡터 합
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vplus_(t_vec3 vec, double x, double y, double z);

// 벡터 차
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus_(t_vec3 vec, double x, double y, double z);

// 벡터 스칼라곱
t_vec3		vmult(t_vec3 vec, double t);

// 벡터의 각 원소끼리 곱셈
t_vec3		vmult_(t_vec3 vec, t_vec3 vec2);

// 벡터 스칼라 나눗셈
t_vec3		vdivide(t_vec3 vec, double t);

// 내적
double		vdot(t_vec3 vec, t_vec3 vec2);
// 외적
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);

// 단위벡터
t_vec3		vunit(t_vec3 vec);

// 두 벡터의 원소를 비교하여 작은 값들만 반환
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);


/*** object utils ***/
void        oadd(t_object **list, t_object *new);
t_object    *olast(t_object *list);

#endif
