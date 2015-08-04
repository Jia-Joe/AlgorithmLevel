//Decimation in frequency
#include <stdio.h>
#include <stdlib.h>
#include "ComplexNumOperation.h"
#include "FFT.h"

icomplex* dif(icomplex *X, uint L)
{
	uint N = 1 << L;
	uint N2 = N, N1;//N2=2*N1
	icomplex U, T, W;//U=Wr
	double tmp;

	//�����m������
	for (uint m = 1; m <= L; m++)
	{
		N1 = N2;//N2Ϊ�����������ڵ�ľ���
		N1 >>= 1;
		U = ixcon(1.0, 0);
		tmp = PI / N1;
		W = ixcon(cos(tmp), -sin(tmp));
		for (uint k = 0; k < N1; k++)
		{
			for (uint i = k; i < N; i += N2)
			{
				uint ip = i + N1;
				icomplex t1 = X[i], t2 = X[ip];
				T = iminus(t1, t2);
				X[i] = iadd(t1,t2);
				X[ip] = imul(T, U);
			}
			U = imul(U, W);
		}
	}

	//����ԭ����
	icomplex *Xout = (icomplex*)malloc(sizeof(icomplex)*N);
	//�����еĵ�λ��	
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
		Xout[i] = X[y];
	}

	return Xout;
}

int main()
{
	uint n;
	scanf("%d", &n);
	uint L = 0, N = getN(n, &L);
	printf("%d,%d\n", N, L);
	icomplex *arrayin = (icomplex*)malloc(sizeof(icomplex)*N);
	icomplex *arrayout;
	for (uint i = 0; i < n; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		icomplex x = { tmp, 0.0 };
		arrayin[i] = x;
	}
	icomplex lfnull = { 0.0, 0.0 };
	for (uint i = n; i < N; i++)
		arrayin[i] = lfnull;


	arrayout = dif(arrayin, L);
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
