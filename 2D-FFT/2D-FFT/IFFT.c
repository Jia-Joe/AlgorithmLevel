#include "IFFT.h"
#include <stdlib.h>
#include <stdio.h>

void conj(icomplex *X, uint n)
{
	for (uint i = 0; i < n; i++)
	{
		X[i].im = -X[i].im;
	}
}
icomplex* ifft(icomplex *X, uint L)
{
	uint N = 1 << L;
	for (uint i = 0; i < N; i++)
	{
		X[i].im = -X[i].im;
	}
	icomplex *Y=fft(X,L);
	for (uint i = 0; i < N; i++)
	{
		Y[i].im = -Y[i].im;
	}
	for (uint i = 0; i < N; i++)
	{
		Y[i].re /= N;
		Y[i].im /= N;
	}
	return Y;
}

int mainIFFT()
{
	icomplex a[4] = { { 6.0000, 0 }, { -1.0000, 1.0000 }, { -4.0000, 0 }, { -1.0000,-1.0000 } };
	icomplex *arrayout = ifft(a, 2);
	printf("IFFT:\n");
	for (uint i = 0; i < 4; i++)
	{
		ixprint(arrayout[i]);
		printf("\n");
	}
	free(arrayout);

	getchar();
	getchar();
	return 0;
}