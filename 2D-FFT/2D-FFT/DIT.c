//Decimation in time
#include <stdio.h>
#include <stdlib.h>

#include "FFT.h"



int main()
{
	uint n;
	scanf("%d", &n);
	uint L = 0, N = getN(n, &L);
	printf("%d,%d\n", N, L);
	icomplex *arrayin = (icomplex*)malloc(sizeof(icomplex)*N);
	icomplex *arrayout = (icomplex*)malloc(sizeof(icomplex)*N);
	for (uint i = 0; i < n; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		icomplex x = { tmp, 0.0 };
		arrayin[i] =x;
	}
	icomplex lfnull = { 0.0, 0.0 };
	for (uint i = n; i < N; i++)
		arrayin[i] = lfnull;

	BitReverse(arrayin, arrayout, N, L);
	//Êä³öµ¹Î»Ðò
	for (uint i = 0; i < N; i++)
	{
		ixprint(arrayout[i]);
		printf(" %d\n", i);
	}
	icomplex a = ixcon(11, 0), b = ixcon(22, 0), c = ixcon(33, 0), d = ixcon(44, 0);
	icomplex arrayou[4];
	arrayou[0] = a; arrayou[1] = b; arrayou[3] = c; arrayou[3] = d;
	arrayout=fft(&arrayout, L);
	printf("FFT:\n");
	for (uint i = 0; i < N; i++)
	{
		ixprint(arrayout[i]);
		printf("\n");
	}
	free(arrayin);
	free(arrayout);


	getchar();
	getchar();
	return 0;
}

