// DFStree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define VER 16

bool marked[VER] = { false };
void dfs(EdgeWeightedGraph &G, int v)
{
	marked[v] = true;
	cout << v << " ";
	for (Edge e : G.adjGet(v))
	{
		int w = e.other(v);
		if (!marked[w])
		{
			dfs(G, w);
		}
	}
}

int _tmain0(int argc, _TCHAR* argv[])
{
	EdgeWeightedGraph G(VER);
	dfs(G, 0);

	system("pause");
	return 0;
}

