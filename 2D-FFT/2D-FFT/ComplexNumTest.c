
#include "ComplexNumOperation.h"
//#include <complex.h>


int main()
{
	//_Dcomplex cx=_Cbuild(3.0, 4.0);
	//double w = cabs(cx);
	//printf("\n\nThe conjugate of cx =  %.2f%",w);
	icomplex ax = { 1, 2 },bx = { 2, 3 };
	icomplex cx = iadd(ax, bx);
	printf("%.2f--%.2f\n", cx.re,cx.im);
	ecomplex ex = { 2.8, 3.3 };
	ixprint(cx);
	exprint(ex);

	getchar();
	return 0;
}