#include "FFT.h"
#include <stdlib.h>
#include <stdio.h>

//采样点数N,L=logN
uint getN(uint n, uint *l)
{
	uint c = 2;
	*l = 1;
	while (c < n)
	{
		c = c << 1;
		(*l)++;
	}
	return c;
}
uint bitr(uint x, uint n)
{
	uint y = 0;
	for (x; n; x >>= 1)
	{
		y <<= 1;
		y |= x & 1;
		n--;
	}
	return y;
}
//序列的倒位序
void BitReverse(icomplex *before, icomplex *after, uint n, uint l)
{
	//	uint *tmp = (uint*)malloc(sizeof(uint)*n);
	for (uint i = 0; i < n; i++)
	{
		//		tmp[i] = bitr(n, l);
		after[i] = before[bitr(i, l)];
	}
}
icomplex* fft(icomplex *Xin, uint L)
{
	uint N = 1 << L;
	uint N2 = 1, N1;//N2=2*N1
	icomplex U, T, W;//U=Wr
	double tmp;
	//拷贝原序列
	icomplex *X = (icomplex*)malloc(sizeof(icomplex)*N);
	//求序列的倒位序	
	for (uint i = 0; i < N; i++)
	{
		uint y = 0, x = i;
		uint ltmp = L;
		for (x; ltmp; x >>= 1)
		{
			y <<= 1;
			y |= x & 1;
			ltmp--;
		}
		X[i]=Xin[y];
	}
	//计算第m级序列
	for (uint m = 1; m <= L; m++)
	{
		N1 = N2;//N2为蝶形运算两节点的距离
		N2 <<= 1;
		U = ixcon(1.0, 0);
		tmp = PI / N1;
		W = ixcon(cos(tmp), -sin(tmp));
		for (uint k = 0; k < N1; k++)
		{
			for (uint i = k; i < N; i += N2)
			{
				uint ip = i + N1;
				T = imul(X[ip], U);

				X[ip] = iminus(X[i], T);
				X[i] = iadd(X[i], T);
			}
			U = imul(U, W);
		}
	}

	return X;
}
//void fft(icomplex *X, uint L)
//{
//	uint N = 1 << L;
//	uint N2 = 1, N1;//N2=2*N1
//	icomplex U, T, W;//U=Wr
//	double tmp;
//	//拷贝原序列
//	icomplex *tmparray = (icomplex*)malloc(sizeof(icomplex)*N);
//	for (uint i = 0; i < N; i++)
//	{
//		printf("%lf--%lf\n", X[i].re, X[i].im);
//		tmparray[i] = ixcon(X[i].re, X[i].im);
//		//printf("array%lf--%lf\n", tmparray[i].re, tmparray[i].im);
//	}
//	//求序列的倒位序	
//	for (uint i = 0; i < N; i++)
//	{
//		uint y = 0, x = i;
//		uint ltmp = L;
//		for (x; ltmp; x >>= 1)
//		{
//			y <<= 1;
//			y |= x & 1;
//			ltmp--;
//		}
//		printf("%d\n", y);
//		X[i] = tmparray[y];
//	}
//	free(tmparray);
//	for (uint i = 0; i < N; i++)
//	{
//		printf("%lf--%lf\n", X[i].re, X[i].im);
////		printf("array%lf--%lf\n", tmparray[i].re, tmparray[i].im);
//	}
//	//计算第m级序列
//	for (uint m = 1; m <= L; m++)
//	{
//		N1 = N2;//N2为蝶形运算两节点的距离
//		N2 <<= 1;
//		U = ixcon(1.0, 0);
//		tmp = PI / N1;
//		W = ixcon(cos(tmp), -sin(tmp));
//		for (uint k = 0; k < N1; k++)
//		{
//			for (uint i = k; i < N; i += N2)
//			{
//				uint ip = i + N1;
//				T = imul(X[ip], U);
//
//				X[ip] = iminus(X[i], T);
//				X[i] = iadd(X[i], T);
//			}
//			U = imul(U, W);
//		}
//	}
//}

icomplex* ppfft(icomplex **X, uint L)
{
	//printf("%lf--%lf\n", (*X)[2].re, (*X)[2].im);
	uint N = 1 << L;
	uint N2=1, N1;//N2=2*N1
	icomplex U, T, W;//U=Wr
	double tmp;
	//计算第m级序列
	for (uint m = 1; m <= L; m++)
	{
		N1 = N2;//N2为蝶形运算两节点的距离
		N2 <<= 1;
		U = ixcon(1.0, 0);
		tmp = PI / N1;
		W = ixcon(cos(tmp), -sin(tmp));
		for (uint k = 0; k < N1; k++)
		{
			for (uint i = k; i < N; i += N2)
			{
				uint ip = i + N1;
	//			printf("%lf--%lf\n", (*X)[ip].re, U.re);
				T = imul((*X)[ip], U);

				(*X)[ip] = iminus((*X)[i], T);
				(*X)[i] = iadd((*X)[i], T);
			}
			U = imul(U, W);
		}
//		printf("%lf--%lf\n", (*X)[0].re, (*X)[0].im);
	}

	return *X;
}

icomplex* pfft(icomplex *X, uint L)
{
	uint N = 1 << L;
	uint N2 = 1, N1;//N2=2*N1
	icomplex U, T, W;//U=Wr
	double tmp;
	//计算第m级序列
	for (uint m = 1; m <= L; m++)
	{
		N1 = N2;//N2为蝶形运算两节点的距离
		N2 <<= 1;
		U = ixcon(1.0, 0);
		tmp = PI / N1;
		W = ixcon(cos(tmp), -sin(tmp));
		for (uint k = 0; k < N1; k++)
		{
			for (uint i = k; i < N; i += N2)
			{
				uint ip = i + N1;
				T = imul(X[ip], U);

				X[ip] = iminus(X[i], T);
				X[i] = iadd(X[i], T);
			}
			U = imul(U, W);
		}
	}
	return X;
}
