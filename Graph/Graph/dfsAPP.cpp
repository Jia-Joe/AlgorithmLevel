#pragma once
#include "stdafx.h"

//���費�����Ի���ƽ�бߣ��ж��Ƿ��޻�ͼ
class Cycle
{
private:
	vector<bool> marked;
	bool hasCycle;
	void dfs(Graph &G, int v, int u)
	{
		marked[v] = true;
		for (int w : *G.getAdj(v))
		{
			if (!marked[w])
			{
				dfs(G, w, v);
			}
			else if (w != u)
			{
				hasCycle = true;
			}
		}
	}
public:
	Cycle(Graph G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
		}
		for (int s = 0; s < G.Vget(); s++)
		{
			if (!marked[s])
			{
				dfs(G,s,s);
			}
		}
	}
	bool has_Cycle()
	{
		return hasCycle;
	}
};

//�ж��Ƿ����ͼ
class TwoColor
{
	vector<bool> marked;
	vector<bool> color;
	bool isTwo=true;
	void dfs(Graph G, int v)
	{
		marked[v] = true;
		for (int w : *G.getAdj(v))
		{
			if (!marked[w])
			{
				color[w] = !color[v];
				dfs(G, w);
			}
			else if (color[w] == color[v])
				isTwo = false;
		}
	}
public:
	TwoColor(Graph G)
	{
		for (int i = 0; i < G.Vget(); i++)
		{
			marked.push_back(false);
			color.push_back(false);
		}
		for (int s = 0; s < G.Vget(); s++)
		{
			if (!marked[s])
			{
				dfs(G, s);
			}
		}
	}
};
