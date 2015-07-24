#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
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
	cout << endl << endl << endl;
	cout<< "The Shortest Paths:" << endl << endl;
	DijkstraAllPairSP alldsp(g);
	for (int i = 0; i < g.Vget(); i++)
	{
		cout <<endl<< "Start From V" << i << ':' << endl << endl;
		for (int k = 0; k < g.Vget(); k++)
			alldsp.printPath(i, k);
	}
	system("pause");
	return 0;
}
