#pragma once
#include "stdafx.h"

class DepthFirstPaths
{
private:
	vector<bool> marked;
	vector<int> edgeTo;
	int s;//Æðµã

	void dfs(Graph &G, int v)
	{
		marked[v] = true;
		vector<int>::iterator it;
		for (it = G.getAdj(v)->begin(); it != G.getAdj(v)->end(); it++)
		{
			if (!marked[*it])
			{
				edgeTo[*it] = v;
				dfs(G, *it);
			}
		}
	}

public:
	DepthFirstPaths(Graph &G, int s)
	{
		this->s = s;
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			edgeTo.push_back(s);
		}
		dfs(G, s);
	}
	bool hasPathTo(int v)
	{
		return marked[v];
	}
	vector<int> pathTo(int v)
	{
		vector<int> path;
		if (!hasPathTo(v))
			return path;
		for (int x = v; x != s; x = edgeTo[x])
			path.push_back(x);
		path.push_back(s);
		return path;
	}
};