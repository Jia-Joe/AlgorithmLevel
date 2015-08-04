#pragma once
#include "ComplexNumOperation.h"


//#define K 32//32位处理器

typedef unsigned int uint;

uint getN(uint n, uint *l);
uint bitr(uint x, uint n);
void BitReverse(icomplex *before, icomplex *after, uint n, uint l);

//按时间抽选DIT
icomplex* fft(icomplex *X, uint L);
icomplex* pfft(icomplex *X, uint L);
icomplex* ppfft(icomplex **X, uint L);
//按频率抽选DIF
icomplex* dif(icomplex *X, uint L);