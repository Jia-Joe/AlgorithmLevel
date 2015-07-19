#pragma once
#include "stdafx.h"


class CC
{
private:
	vector<bool> marked;
	vector<int> id;//每个节点属于哪个连通分量
	int count;
	void dfs(Graph &G, int v)
	{
		marked[v] = true;
		id[v] = count;
		for (int w : *G.getAdj(v))
		{
			if (!marked[w])
			{
				dfs(G, w);
			}
		}
	}
public:
	CC(Graph &G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			id.push_back(0);
		}
		for (int s = 0; s < G.Vget(); s++)
		{
			if (!marked[s])
			{
				dfs(G, s);
				count++;
			}
		}
	}
	bool connected(int v, int w)
	{
		return id[v] == id[w];
	}
	int getid(int v)
	{
		return id[v];
	}
	int getcount()
	{
		return count;
	}
};