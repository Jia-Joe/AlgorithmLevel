#pragma once
#include "ComplexNumOperation.h"


//#define K 32//32λ������

typedef unsigned int uint;

uint getN(uint n, uint *l);
uint bitr(uint x, uint n);
void BitReverse(icomplex *before, icomplex *after, uint n, uint l);

//��ʱ���ѡDIT
icomplex* fft(icomplex *X, uint L);
icomplex* pfft(icomplex *X, uint L);
icomplex* ppfft(icomplex **X, uint L);
//��Ƶ�ʳ�ѡDIF
icomplex* dif(icomplex *X, uint L);