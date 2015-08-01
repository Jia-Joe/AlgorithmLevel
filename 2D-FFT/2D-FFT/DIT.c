//Decimation in time
#include <stdio.h>
#include <stdlib.h>
#include "ComplexNumOperation.h"


#define K 32//32位处理器

typedef unsigned int uint;

//采样点数N,L=logN
uint getN(uint n,uint *l)
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


int main()
{
	uint n;
	scanf("%d", &n);
	icomplex *arrayin = (icomplex*)malloc(sizeof(icomplex)*n);
	for (uint i = 0; i < n; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		icomplex x = { tmp, 0.0 };
		arrayin[i] =x;
	}
	for (uint i = 0; i < n; i++)
	{
		ixprint(arrayin[i]);

	//	printf("%lf\n", arrayin[i]);
	}
	free(arrayin);
	uint L = 0,N=getN(n,&L);
	printf("%d,%d\n",N,L);
	printf("%d,%d\n", bitr(1,3),bitr(2,3));

	getchar();
	getchar();
	return 0;
}

