#pragma once
#include "stdafx.h"

class DijkstraSP
{
private:
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
				edgeTo.push_back(e);
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
		pq.IndexMinPQInit(G.Vget());
		for (int i = 0; i < G.Vget(); i++)
		{
			Edge newE(0, 0, INF);
			edgeTo.push_back(newE);
			disTo.push_back(INF);
		}
		disTo[s] = 0.0;
		pq.insert(0, 0.0);
		while (!pq.isEmpty())
			relax(G, pq.delMin());
	}
	double disToV(int v)
	{
		return disTo[v];
	}
	bool hasPathTo(int v)
	{
		return !disTo[v] == INF;
	}
	void printPathTo(int v)
	{
		if (!hasPathTo(v))
			cout << "No path to " << v << endl;
		else
		{
			cout << "<V" << v << ">";
			for (Edge x = edgeTo[v]; x.weightGet != 0.0; x = edgeTo[x.from()])
			{
				cout << "<--" << x.from() << '[' << x.weightGet() << ']';
			}
			cout << endl;
		}

	}
};