#pragma once
#include "stdafx.h"

class DirectDFS
{
private:
	vector<bool> marked;
	void dfs(Digraph &G, int v)
	{
		marked[v] = true;
		for (int w : *G.getAdj(v))
		{
			if (!marked[w])
			{
				dfs(G, w);
			}
		}
	}
public:
	DirectDFS(Digraph &G, int s)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		for (int v = 0; v < G.Vget(); v++)
		{
			if (!marked[v])
				dfs(G, v);
		}
	}
	DirectDFS(Digraph G, vector<int> sources)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		for (int s : sources)
		{
			if (!marked[s])
				dfs(G, s);
		}
	}
	bool markedv(int v)
	{
		return marked[v];
	}
};