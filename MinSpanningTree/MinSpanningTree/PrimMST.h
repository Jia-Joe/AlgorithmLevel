#pragma once
#include "stdafx.h"

class LazyPrimMST
{
private:
	vector<bool> marked;//标记最小生成树的顶点
	vector<Edge> mst;//最小生成树的边
	priority_queue<Edge> pq;//横切边（包括失效的边）
	void visit(EdgeWeightedGraph &G, int v)
	{
		//标记v并将所有连接v和未标记顶点的边加入pq
		marked[v]=true;
		for (Edge e : G.adjGet(v))
		{
			if (!marked[e.other(v)])
				pq.push(e);
		}
	}
public:
	LazyPrimMST(EdgeWeightedGraph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		visit(G, 0);
		while (!pq.empty())
		{
			Edge e = pq.top();
			pq.pop();
			int v = e.either(),w=e.other(v);
			if (marked[v] && marked[w])
				continue;
			mst.push_back(e);
			if (!marked[v])
				visit(G, v);
			else
				visit(G, w);
		}
	}

	vector<Edge> mstGet()
	{
		return mst;
	}
	double weightGet()
	{
		double wsum=0;
		for (Edge e : mst)
		{
			wsum += e.weightGet();
		}
		return wsum;
	}
};

class PrimMST
{
	
};