#pragma once
#include "stdafx.h"

/********************************************************************
Kosaraju Algorithm:
在有向图中寻找连通分量，代码在CC的基础上改进
1.Digraph取reverse，得到有向图Gr
2.对Gr用DepthFirstOrder顶点取后逆序
3.按以上顺序访问原图G中的各个顶点
*********************************************************************/

class SCC
{
private:
	vector<bool> marked;
	vector<int> id;
	int count=0;
	void dfs(Digraph &G, int v)
	{
		marked[v] = true;
		id[v] = count;
		if (!(G.getAdj(v)->empty()))
		{
			for (int w : *G.getAdj(v))
			{
				if (!marked[w])
					dfs(G, w);
			}
		}

	}
public:
	SCC(Digraph &G)
	{
		Digraph Gr = G.reverse();
		//DepthFirstOrder ord(G.reverse());
		DepthFirstOrder ord(Gr);
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			id.push_back(0);
		}
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