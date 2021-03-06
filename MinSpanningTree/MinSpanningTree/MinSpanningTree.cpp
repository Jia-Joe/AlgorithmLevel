// MinSpanningTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define N 8

int _tmain(int argc, _TCHAR* argv[])
{
	EdgeWeightedGraph g(N);
	g.print();
	//KruskalMST mst(g);
	//LazyPrimMST mst(g);
	PrimMST mst(g);
	for (Edge e : mst.mstGet())
	{
		int v1 = e.either();
		int w1 = e.other(v1);
		cout << v1 << "--" << w1 <<endl;
	}
	cout << "MST Weight: " << mst.weightGet() << endl;
	system("pause");
	return 0;
}
