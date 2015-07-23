#include "stdafx.h"

#define N 8

int _tmain1(int argc, _TCHAR* argv[])
{

	EdgeWeightedDigraph g(N);
	int E;
	cin >> E;
	for (int i = 0; i < E; i++)
	{
		int v, w;
		double we;
		cin >> v >> w >> we;
		Edge e(v, w, we);
		g.addEdge(e);
	}
	g.print();

	system("pause");
	return 0;
}