#pragma once
#include "stdafx.h"

//拓扑排序：有向无环图中的最优算法，可以处理负权边
//若求最长路径，可以将权值变为负值，再求最短路径
class AcyclicSP
{
private:
	int s;
	vector<Edge> edgeTo;
	vector<double> disTo;
	void relax(EdgeWeightedDigraph &G, int v)
	{
		for (Edge e : G.adjGet(v))
		{
			int w = e.to();
			if (disTo[w] > disTo[v] + e.weightGet())
			{
				disTo[w] = disTo[v] + e.weightGet();
				edgeTo[w] = e;
			}
		}
	}
public:
	AcyclicSP(EdgeWeightedDigraph &G, int s)
	{
		this->s = s;
		Topological tps(G);
		vector<int> ord = tps.gTopoSort();
		for (int i = 0; i < G.Vget(); i++)
		{
			if (i == s)
			{
				Edge e0(i, i, 0.0);
				edgeTo.push_back(e0);
				disTo.push_back(0.0);
			}
			else
			{
				Edge newE(0, 0, INF);
				edgeTo.push_back(newE);
				disTo.push_back(INF);
			}
		}
		for (int v : ord)
			relax(G, v);
	}
	double disToV(int v)
	{
		return disTo[v];
	}
	bool hasPathTo(int v)
	{
		return !(disTo[v] == INF);
	}
	void printPathTo(int v)
	{
		if (!hasPathTo(v))
			cout << "No path to " << v << endl;
		else
		{
			cout << "[V" << s << "->V" << v << " (" << setw(4) << disTo[v] << setw(3) << ")] " << s;
			stack<int> path;
			int x = v;
			do
			{
				path.push(x);
				x = edgeTo[x].from();
			} while (edgeTo[x].to() != s);
			int pathSize = path.size();
			if (v != s)
			{
				for (int i = 0; i < pathSize; i++)
				{
					cout << "-->" << path.top();
					path.pop();
				}
			}
			cout << endl;
		}
	}
};
