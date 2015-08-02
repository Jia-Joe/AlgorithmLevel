#include "FFT.h"

//��������N,L=logN
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
//���еĵ�λ��
void BitReverse(icomplex *before, icomplex *after, uint n, uint l)
{
	//	uint *tmp = (uint*)malloc(sizeof(uint)*n);
	for (uint i = 0; i < n; i++)
	{
		//		tmp[i] = bitr(n, l);
		after[i] = before[bitr(i, l)];
	}
}

icomplex* fft(icomplex **X, uint L)
{
	//printf("%lf--%lf\n", (*X)[2].re, (*X)[2].im);
	uint N = 1 << L;
	uint N2=1, N1;//N2=2*N1
	icomplex U, T, W;//U=Wr
	double tmp;
	//�����m������
	for (uint m = 1; m <= L; m++)
	{
		N1 = N2;//N2Ϊ�����������ڵ�ľ���
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