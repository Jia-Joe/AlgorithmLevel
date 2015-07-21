#pragma once
#include "stdafx.h"
#define N 13

int _tmain0(int argc, _TCHAR* argv[])
{
	Digraph g(N);
	g.print();

	DirectDFS dfs(g, 0);
	for (int i = 0; i < N; i++)
		cout << "--" << dfs.markedv(i);
	cout << endl << endl;

	//DirectedCycle cyc(g);
	//if (cyc.hasCycle())
	//{
	//	cout << "NULL" << endl;
	//}
	//else
	//{
		DepthFirstOrder ord(g);
		queue<int> q1 = ord.gpre();
		queue<int> q2 = ord.gpost();
		stack<int> s1 = ord.greversePost();
		int cq1 = q1.size();
		int cq2 = q2.size();
		int cs1 = s1.size();
		cout << "pre-";
		for (int i = 0; i <cq1; i++)
		{
			cout << '-' << q1.front();
			q1.pop();
		}
		cout << endl;
		cout << "post";
		for (int i = 0; i <cq2; i++)
		{
			cout << '-' << q2.front();
			q2.pop();
		}
		cout << endl << endl;
		cout << "reversePost/TopoSort:";
		cout << endl;
		for (int i = 0; i <cs1; i++)
		{
			cout << "->" << s1.top();
			s1.pop();
		}
		cout << endl ;
		for (int i = 0; i <cs1; i++)
		{
			cout << "->" << ord.gTopoSort()[i];
		}
		cout << endl;
	//}

	system("pause");
	return 0;
}