#include <stdio.h>
#include "ComplexNumOperation.h"

double igetR(icomplex x)
{
	double a = x.re,b = x.im;
	return sqrt(a*a + b*b);
}
double igetTheta(icomplex x)
{
	return atan2(x.im , x.re);
}
double egetRe(ecomplex x)
{
	return x.r*cos(x.theta);
}
double egetIm(ecomplex x)
{
	return x.r*sin(x.theta);
}

icomplex e2icomplex(ecomplex x)
{
	icomplex ix = { egetRe(x), egetIm(x) };
	return ix;
}
ecomplex i2ecomplex(icomplex x)
{
	ecomplex ex = { igetR(x), igetTheta(x) };
	return ex;
}

icomplex iadd(icomplex a, icomplex b)
{
	icomplex c = { a.re + b.re, a.im + b.im };
	return c;
}
icomplex iminus(icomplex a, icomplex b)
{
	icomplex c = { a.re - b.re, a.im - b.im };
	return c;
}
icomplex imul(icomplex a, icomplex b)
{
	icomplex c = \
	{ a.re*b.re - a.im*b.im , a.im*b.re+a.re*b.im };
	return c;
}
icomplex idiv(icomplex a, icomplex b)
{
	double den = b.re*b.re + b.im*b.im;
	icomplex c=\
	{ a.re*b.re + a.im*b.im, a.im*b.re - a.re*b.im };
	return c;
}

ecomplex eadd(ecomplex a, ecomplex b)
{
	icomplex ca = e2icomplex(a);
	icomplex cb = e2icomplex(b);
	icomplex c = iadd(ca, cb);
	return i2ecomplex(c);
}
ecomplex eminus(ecomplex a, ecomplex b)
{
	icomplex ca = e2icomplex(a);
	icomplex cb = e2icomplex(b);
	icomplex c = iminus(ca, cb);
	return i2ecomplex(c);
}
ecomplex emul(ecomplex a, ecomplex b)
{
	ecomplex c = { a.r*b.r, a.theta + b.theta };
	return c;
}
ecomplex ediv(ecomplex a, ecomplex b)
{
	ecomplex c = { a.r/b.r, a.theta - b.theta };
	return c;
}

#ifndef _COMPLEX_J_
void ixprint(icomplex ix)
{
	printf(" %f + i*%f ", ix.re, ix.im);
}
void exprint(ecomplex ex)
{
	printf(" %fe^i*%f ", ex.r,ex.theta);
}
#else
void ixprint(icomplex ix)
{
	printf(" [%.2f]+j[%.2f] ", ix.re, ix.im);
}
void exprint(ecomplex ex)
{
	printf(" [%.2f]e^j*[%.2f] ", ex.r, ex.theta);
}
#endif
