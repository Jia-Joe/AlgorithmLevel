#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **a;
	int m, n, i, k;

	scanf("%d%d", &m, &n);

	a = (int**)malloc(m*sizeof(int*));
	for (i = 0; i<m; i++)
		a[i] = (int*)malloc(n*sizeof(int));

	for (i = 0; i < m; i++)
	{
		for (k = 0; k < n; k++)
		{
			a[i][k] = i + 2 * k;
			printf("%d   ", a[i][k]);
		}
		printf("\n");
	}

	getchar();
	getchar();
	return 0;
}