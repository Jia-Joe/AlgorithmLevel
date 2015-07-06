// Graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//typedef vector<int> vint;
	//vector<vint> adj;
	Graph g(7);
	g.cinEdge();
	g.print();

	system("pause");
	return 0;
}

