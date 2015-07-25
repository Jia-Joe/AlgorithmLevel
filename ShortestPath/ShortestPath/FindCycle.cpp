#include "stdafx.h"

#include "FindCycle.h"

#define N 8

int _tmainCy(int argc, _TCHAR* argv[])
{

	EdgeWeightedDigraph g(N);
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
	cout << endl;
	FindCycle fc(g);
	if (!fc.hasCycle())
		cout << "No Cycle" << endl;
	else
	{	
		stack<int> stk = fc.getcycle();
		int sz = stk.size();
		for (int i = 0; i < sz; i++)
		{
			cout << stk.top() << "-->";
			stk.pop();
		}
	}
	cout << endl;
	system("pause");
	return 0;
}