// NetworkFlows.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FordFulkerson.h"

int _tmain(int argc, _TCHAR* argv[])
{
	FlowNetwork g(6);
	int E;
	cin >> E;
	for (int i = 0; i < E; i++)
	{
		int v, w;
		double we;
		cin >> v >> w >> we;
		FlowEdge eIn(v, w, we);
		g.addEdge(eIn);
	}
	g.print();
	FordFulkerson maxflow(g, 0, 5);
	cout << endl;
	for (FlowEdge e : g.allEdge())
		cout << e.from() << "-->" << e.to() << " capacity:" << e.capacityGet() << " flow:" << e.flowGet()<<endl;
	cout << endl << "Max flow value:" << maxflow.valueGet()<<endl;



	system("pause");
	return 0;
}

