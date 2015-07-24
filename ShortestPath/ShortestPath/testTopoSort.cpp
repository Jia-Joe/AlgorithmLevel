#include "stdafx.h"

int _tmainTS(int argc, _TCHAR* argv[])
{
	EdgeWeightedDigraph g(8);
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

	Topological tps(g);
	for (int i = 0; i < g.Vget(); i++)
		cout << tps.gTopoSort()[i] << "-->";
	system("pause");
	return 0;
}