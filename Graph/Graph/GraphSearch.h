#pragma once
#include "stdafx.h"
#include "Graph.h"

class DepthFirstSearch
{
private:
	vector<bool> marked;
	int count;
	int v;
public:
	DepthFirstSearch(Graph &G)
	{
		v = G.Vget()-1;
		count = 0;
		for (int i = 0; i < v; i++)
		{
			marked.push_back(false);
		}
		dfs(G, v);
	}
	void dfs(Graph &G,int v)
	{
		marked[v] = true;
		count++;
		vector<int>::iterator it;
		for (it = G.getAdj(v)->begin(); it != G.getAdj(v)->end(); it++)
		{
			if (!marked[*it])
				dfs(G, *it);
		}
	}
	bool Marked(int w)
	{

		return marked[w];
	}
	int Count()
	{
		return count;
	}
};