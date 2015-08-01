//Decimation in frequency
#include <stdio.h>
#include <stdlib.h>
#include "ComplexNumOperation.h"


#define K 32//32λ������

typedef unsigned int uint;

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





int main2()
{
	
	//_Dcomplex cx=_Cbuild(3.0, 4.0);
	//double w = cabs(cx);
	//printf("\n\nThe conjugate of cx =  %.2f%",w);
	double ax = sin(2);
	printf("%.2f\n", ax);
	getchar();
	return 0;
}