#pragma once
#include "FFT.h"

//对序列中的所有元素求共轭
void conj(icomplex *X, uint n);
icomplex* ifft(icomplex *X, uint L);

