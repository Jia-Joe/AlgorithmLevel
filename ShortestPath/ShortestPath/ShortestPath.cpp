// ShortestPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmainDijkSP(int argc, _TCHAR* argv[])
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
	cout <<endl<< "The Shortest Paths:" << endl;
	DijkstraSP dsp(g, 0);
	for (int i = 0; i < g.Vget(); i++)
		dsp.printPathTo(i);

	system("pause");
	return 0;
}

