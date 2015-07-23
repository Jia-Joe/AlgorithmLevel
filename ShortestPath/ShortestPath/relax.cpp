#include "stdafx.h"

vector<Edge> edgeTo;
vector<double> distTo;

void relax(Edge &e)
{
	int v = e.from(), w = e.to();
	if (distTo[w] > distTo[v] + e.weightGet())
	{
		distTo[w] = distTo[v] + e.weightGet();
		edgeTo[w] = e;
	}
}

void relax(EdgeWeightedDigraph &G, int v)
{
	for (Edge e : G.adjGet(v))
	{
		int w = e.to();
		if (distTo[w] > distTo[v] + e.weightGet())
		{
			distTo[w] = distTo[v] + e.weightGet();
			edgeTo[w] = e;
		}
	}
}

double distToGet(int v)
{
	return distTo[v];
}
bool hasPathTo(int v)
{
	return distTo[v] < INF;
}
vector<Edge> pathTo(int v)
{
	vector<Edge> path;
	if (!hasPathTo(v))
		return path;
	for (Edge *e = &edgeTo[v]; e != NULL; e = &edgeTo[e->from()])
		path.push_back(*e);
	return path;
}
