#include "stdafx.h"

#include "AcyclicSP.h"


int _tmainASP(int argc, _TCHAR* argv[])
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
	cout << endl << "The Shortest Paths:" << endl;
	AcyclicSP asp(g, 3);
	for (int i = 0; i < g.Vget(); i++)
		asp.printPathTo(i);

	system("pause");
	return 0;
}
