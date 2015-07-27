#pragma once 
#include "stdafx.h"
#include "MaxFlowFun.h"
#include "FlowNetwork.h"
//最短增广路径算法
class FordFulkerson
{
private:
	vector<bool> marked;//剩余网络中是否存在s到v的路径
	vector<FlowEdge> edgeTo;//从s到v的最短路径上最后一条边
	double value;//当前最大流量

	bool hasAugmentingPath(FlowNetwork &G, int s, int t)
	{
		marked[s] = true;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			for (FlowEdge e : G.adjGet(v))
			{
				int w = e.other(v);
				if (e.residualCapacityTo(w)>0&&!marked[w])
				{
					edgeTo[w] = e;
					marked[w] = true;
					q.push(w);
				}
			}
		}
		return marked[t];
	}
public:
	FordFulkerson(FlowNetwork &G, int s, int t)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			FlowEdge e0(0, 0, 0);
			edgeTo.push_back(e0);
		}
		while (hasAugmentingPath(G, s, t))
		{
			//利用所有存在的增广路径计算当前的瓶颈容量
			double bottle = INF;
			for (int v = t; v != s; v = edgeTo[v].other(v))
			{
				if (bottle > edgeTo[v].residualCapacityTo(v))
					bottle = edgeTo[v].residualCapacityTo(v);
			}
			//增大流量
			for (int v = t; v != s; v = edgeTo[v].other(v))
				edgeTo[v].addResidualFlowTo(v, bottle);
			value += bottle;
		}
	}
	double valueGet(){ return value; }
	bool inCut(int v){ return marked[v]; }
	
};
