#pragma once
#include "stdafx.h"

#include "EdgeWeightedDigraph.h"
#include "IndexMinPQ.h"

class DijkstraSP
{
private:
	int s;
	vector<Edge> edgeTo;
	vector<double> disTo;
	IndexMinPQ<double> pq;
	void relax(EdgeWeightedDigraph &G, int v)
	{
		for (Edge e : G.adjGet(v))
		{
			int w = e.to();
			if (disTo[v] + e.weightGet() < disTo[w])
			{
				disTo[w] = disTo[v] + e.weightGet();
				edgeTo[w] = e ;
				if (pq.contains(w))
					pq.change(w, disTo[w]);
				else
					pq.insert(w, disTo[w]);
			}
		}
	}
public:
	DijkstraSP(EdgeWeightedDigraph &G, int s)
	{
		this->s = s;
		pq.IndexMinPQInit(G.Vget());
		for (int i = 0; i < G.Vget(); i++)
		{
			Edge newE(0, 0, INF);
			edgeTo.push_back(newE);
			disTo.push_back(INF);
		}
		disTo[s] = 0.0;
		Edge e0(s, s, 0.0);
		edgeTo[s] = e0;
		pq.insert(s, 0.0);
		while (!pq.isEmpty())
			relax(G, pq.delMin());
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
			//for (int x = v; edgeTo[x].from() != s; x = edgeTo[x].to())
			//{
			//	cout << x << '[' << edgeTo[x].weightGet() << ']' << "<--";
			//}
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

class DijkstraAllPairSP
{
private:
	int V;
	vector<DijkstraSP> all;
public:
	DijkstraAllPairSP(EdgeWeightedDigraph &G)
	{
		V = G.Vget();
		for (int vp = 0; vp < G.Vget(); vp++)
		{
			DijkstraSP tmpSP(G, vp);
			all.push_back(tmpSP);
		}
	}
	double distPair(int s, int t)
	{
		return all[s].disToV(t);
	}
	void printPath(int s, int t)
	{
		all[s].printPathTo(t);
	}
};