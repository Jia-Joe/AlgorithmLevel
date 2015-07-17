#pragma once
#include "stdafx.h"
//#include "Graph.h"
//#include"GraphSearch.h"

//int degree(Graph &G, int v);

int _tmain(int argc, _TCHAR* argv[])
{
	//typedef vector<int> vint;
	//vector<vint> adj;
	Graph g(6);
	cout << degree(g, 1) << endl;
	g.print();
	DepthFirstSearch dfs(g);
	for (int i = 0; i < 6; i++)
		cout << "--" << dfs.Marked(i);
	cout<< endl<<dfs.Count()<<endl;
	system("pause");
	return 0;
}

