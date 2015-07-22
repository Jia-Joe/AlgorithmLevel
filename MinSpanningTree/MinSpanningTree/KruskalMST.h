#pragma once
#include "stdafx.h"

//利用Union-Find数据结构来识别会形成环的边
//Space:E,Time:ElogE

class KruskalMST
{
private :
	vector<Edge> mst;
public:
	KruskalMST(EdgeWeightedGraph &G)
	{
		priority_queue<Edge> pq;
		for (int v = 0; v < G.Vget(); v++)
		{
			for (Edge e : G.adjGet(v))
			{
				pq.push(e);
			}
		}
		UF uf(G.Vget());
		while (!pq.empty()&&mst.size()<G.Vget()-1)
		{
			Edge e = pq.top();
			pq.pop();
			int v = e.either(), w = e.other(v);
			if (uf.connected(v, w))
				continue;
			uf.Union(v, w);
			mst.push_back(e);
		}
	}
	vector<Edge> mstGet()
	{
		return mst;
	}
	double weightGet()
	{
		double wsum = 0;
		for (Edge e : mst)
		{
			wsum += e.weightGet();
		}
		return wsum;
	}
};