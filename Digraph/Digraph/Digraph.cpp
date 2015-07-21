// Digraph.cpp : 定义控制台应用程序的入口点。
//

#pragma once
#include "stdafx.h"
#define N 13

bool reachable(Digraph &G,int v, int w)
{
	vector<DirectDFS> all;
	for (int x = 0; x < G.Vget(); x++)
	{
		DirectDFS all0(G,x);
		all.push_back(all0);
	}
	return all[v].markedv(w);
}
int _tmain(int argc, _TCHAR* argv[])
{
	Digraph g(N);
	g.print();

	DirectDFS dfs(g,0);
	for (int i = 0; i < N; i++)
		cout << "--" << dfs.markedv(i);
	cout <<  endl << endl;
	DirectedCycle cyc(g);
	stack<int> st = cyc.getcycle();
	for (int i = 0; i <= st.size(); i++)
	{
		cout<<'-'<<st.top();
		st.pop();
	}
	cout << endl;
	cout << reachable(g, 0, 11) << reachable(g, 8, 11) << endl;

	system("pause");
	return 0;
}

