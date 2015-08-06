#include <stdio.h>
#include <stdlib.h>

#include "2D-FFT.h"

icomplex** fft2d(icomplex **Xin, uint lgm, uint lgn)
{
	uint m = 1 << lgm;
	uint n = 1 << lgn;
	icomplex **pp;
	pp = (icomplex**)malloc(m*sizeof(icomplex*));
	for (uint i = 0; i < m; i++)
		pp[i] = (icomplex*)malloc(n*sizeof(icomplex));
	for (uint i = 0; i < m; i++)
	{
		pp[i] = fft(Xin[i], lgn);
	}
	for (uint k = 0; k < n; k++)
	{
		icomplex* tmp = (icomplex*)malloc(m*sizeof(icomplex));
		for (uint w = 0; w < m; w++)
			tmp[w] = pp[w][k];
		icomplex* out = fft(tmp, m);
		for (uint w = 0; w < m; w++)
			pp[w][k] = out[w];
		free(tmp);
		free(out);
	}
	return pp;
}

int main()
{
	int m, n;
	icomplex **arrayin, **arrayout;
	scanf("%d%d", &m, &n);
	arrayin = (icomplex**)malloc(m*sizeof(icomplex*));
	for (int i = 0; i < m; i++)
		arrayin[i] = (icomplex*)malloc(n*sizeof(icomplex));
	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++)
		scanf("%lf%lf", &arrayin[i][j].re, &arrayin[i][j].im);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			ixprint(arrayin[i][j]);
		printf("\n");
	}

	uint lgm, lgn, M = getN(m, &lgm), N = getN(n, &lgn);
	arrayout = fft2d(arrayin,lgm,lgn);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			ixprint(arrayout[i][j]);
		printf("\n");
	}

	for (int i = 0; i<m; i++)
		free(arrayin[i]);
	free(arrayin);
	free(arrayout);
	getchar();
	getchar();
	return 0;
}