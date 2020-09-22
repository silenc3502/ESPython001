#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct _complex comp;

struct _complex
{
	float real;
	float imag;
};

typedef struct _phasor phasor;

struct _phasor
{
	float amp;
	float phase;
};

float radian2degree(float rad)
{
	return rad * 180.0f / M_PI;
}

float degree2radian(float deg)
{
	return deg * M_PI / 180.0f;
}

void complex_static_print(comp z)
{
	printf("Real: %.4f, Image: %.4f\n", z.real, z.imag);
}

void complex_print(comp *z)
{
	printf("Real: %.4f, Image: %.4f\n", z->real, z->imag);
}

comp complex_add(comp z1, comp z2)
{
	static comp res;

	res.real = z1.real + z2.real;
	res.imag = z1.imag + z2.imag;

	return res;
}

comp *complex_sub(comp z1, comp z2)
{
	comp *res = (comp *)malloc(sizeof(comp));

	res->real = z1.real - z2.real;
	res->imag = z1.imag - z2.imag;

	return res;
}

comp *complex_mul(comp z1, comp z2)
{
	comp *res = (comp *)malloc(sizeof(comp));

	res->real = z1.real * z2.real - z1.imag * z2.imag;
	res->imag = z1.real * z2.imag + z2.real * z1.imag;

	return res;
}

void complex_scale(comp *z, float scale)
{
	z->real *= scale;
	z->imag *= scale;
}

float magnitude(comp z)
{
	return sqrt(z.real * z.real + z.imag * z.imag);
}

void conjugate(comp *z)
{
	z->imag *= -1;
}

comp *complex_div(comp z1, comp z2)
{
	comp *res;

	float denom = z1.real * z1.real + z1.imag * z1.imag;
	
	conjugate(&z1);

	res = complex_mul(z1, z2);

	complex_scale(res, 1.0f / denom);

	return res;
}

phasor *complex2phasor(comp z)
{
	phasor *res = (phasor *)malloc(sizeof(phasor));

	res->amp = sqrt(z.real * z.real + z.imag * z.imag);
	res->phase = atan2(z.imag, z.real);

	return res;
}

void phasor_print(phasor *p)
{
	printf("Amplitude: %.4f, Phase: %.4f\n", p->amp, p->phase);
}

int main(void)
{
	comp z1 = { 3, 4 };
	comp z2 = { 2, -3 };

	phasor *p1;
	phasor *p2;
	phasor *custom;

	float rad = 1;
	float deg;

	comp r = complex_add(z1, z2);
	comp *res = complex_sub(z1, z2);

	complex_static_print(z1);
	complex_static_print(z2);

	complex_static_print(r);
	complex_print(res);
	free(res);

	res = complex_mul(z1, z2);
	complex_print(res);
	free(res);

	res = complex_div(z1, z2);
	complex_print(res);

	custom = complex2phasor(*res);
	phasor_print(custom);
	deg = radian2degree(custom->phase);
	printf("phase = %.4f, deg = %.4f\n", custom->phase, deg);

	free(custom);
	free(res);

	deg = radian2degree(rad);
	printf("rad = %.4f, deg = %.4f\n", rad, deg);

	rad = degree2radian(deg);
	printf("rad = %.4f, deg = %.4f\n", rad, deg);

	p1 = complex2phasor(z1);
	phasor_print(p1);
	deg = radian2degree(p1->phase);
	printf("phase = %.4f, deg = %.4f\n", p1->phase, deg);

	p2 = complex2phasor(z2);
	phasor_print(p2);
	deg = radian2degree(p2->phase);
	printf("phase = %.4f, deg = %.4f\n", p2->phase, deg);

	free(p1);
	free(p2);


	return 0;
}
