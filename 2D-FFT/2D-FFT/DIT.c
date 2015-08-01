//Decimation in time
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ComplexNumOperation.h"


double *inputx()
{
	int n;
	scanf("%d", &n);
	double *arrayin = (double*)malloc(sizeof(double)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%f", &arrayin[i]);
	}
	return arrayin;
}

int main()
{
	int n;
	scanf("%d", &n);
	double *arrayin = (double*)malloc(sizeof(double)*n);
	for (int i = 0; i < n; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		arrayin[i] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%lf\n", arrayin[i]);
	}
	free(arrayin);
	
	getchar();
	getchar();
	return 0;
}