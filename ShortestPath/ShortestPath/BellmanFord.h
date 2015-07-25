#pragma once
#include "stdafx.h"

//假设起点s无法到达负权环，distTo[s]初始化为0，其余INF,以任意顺序放松有向图的所有边，重复V轮
//归纳法证明，v0->v1->...->vk,第i轮放松，得到s到vi的最短路径，k不会大于V-1

class BellmanFordSP
{
private:
	vector<double> distTo;
	vector<Edge> edgeTo;
	vector<bool> onQ;
	queue<int> queue;
	int cost;//relax调用次数
	vector<Edge> cycle;

	void relax(EdgeWeightedDigraph &G, int v);
	void findNegativeCycle();
public:
	BellmanFordSP(EdgeWeightedDigraph &G, int s);
	bool hasNegtiveCycle();
	vector<Edge> negtiveCycle();

	double disToV(int v)
	{
		return distTo[v];
	}
	bool hasPathTo(int v)
	{
		return !(distTo[v] == INF);
	}
	void printPathTo(int v);
};