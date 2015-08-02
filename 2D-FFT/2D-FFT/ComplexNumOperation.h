#pragma once
#include <math.h>

#define _COMPLEX_J_
#define PI  3.141592653589793

typedef struct
{
	double re;
	double im;
}icomplex;

typedef struct
{
	double r;
	double theta;
}ecomplex;

icomplex ixcon(double a, double b);
ecomplex excon(double a, double b);

double igetR(icomplex x);
double igetTheta(icomplex x);
double egetRe(ecomplex x);
double egetIm(ecomplex x);

icomplex e2icomplex(ecomplex x);
ecomplex i2ecomplex(icomplex x);

icomplex iadd(icomplex a, icomplex b);
icomplex iminus(icomplex a, icomplex b);
icomplex imul(icomplex a, icomplex b);
icomplex idiv(icomplex a, icomplex b);

ecomplex eadd(ecomplex a, ecomplex b);
ecomplex eminus(ecomplex a, ecomplex b);
ecomplex emul(ecomplex a, ecomplex b);
ecomplex ediv(ecomplex a, ecomplex b);

void ixprint(icomplex ix);
void exprint(ecomplex ex);