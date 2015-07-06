#include "stdafx.h"
#include "Graph.h"

//int degree(Graph &G, int v);
int _tmain(int argc, _TCHAR* argv[])
{
	//typedef vector<int> vint;
	//vector<vint> adj;
	Graph g(7);
	cout << degree(g, 1) << endl;
	g.print();
 
	system("pause");
	return 0;
}

