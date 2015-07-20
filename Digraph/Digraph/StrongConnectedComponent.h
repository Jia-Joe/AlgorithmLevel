#pragma once
#include "stdafx.h"

/********************************************************************
Kosaraju Algorithm:在有向图中寻找连通分量
1.Digraph取reverse
2.DepthFirstOrder顶点排序
3.按顺序访问顶点
*********************************************************************/

class SCC
{
private:
	vector<bool> marked;
	vector<int> id;
	int count=0;
	void dfs(Digraph G, int v)
	{
		marked[v] = true;
		id[v] = count;
		for (int w : *G.getAdj(v))
		{
			dfs(G, w);
		}
	}
public:
	SCC(Digraph G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			id.push_back(0);
		}
		Digraph Gr = G.reverse();
		DepthFirstOrder ord(Gr);
		for (int s : ord.gTopoSort())
		{
			if (!marked[s])
			{
				dfs(G, s);
				count++;
			}
		}
	}
	bool stronglyConnected(int v, int w)
	{
		return id[v] == id[w];
	}
	int countget()//强连通分量的总数
	{
		return count;
	}
	int idget(int v)//判断顶点v属于哪个强连通分量
	{
		return id[v];
	}
};