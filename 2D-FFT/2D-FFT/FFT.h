#pragma once
#include "ComplexNumOperation.h"


#define K 32//32Î»´¦ÀíÆ÷

typedef unsigned int uint;

uint getN(uint n, uint *l);
uint bitr(uint x, uint n);
void BitReverse(icomplex *before, icomplex *after, uint n, uint l);
//icomplex* fft(icomplex *X, uint L);

void fft(icomplex *X, uint L);